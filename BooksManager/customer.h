#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "id.h"
#include "person.h"
#include "loan.h"

class Customer :public Person, public ID{
public:
    static int vipnum;
    //friend class clerk;
    Customer() {
        ++vipnum;
        recnum = record.size();
    }

    Customer( const Person& person, const ID& account );
    Customer( const std::string& name, const std::string& id, const std::string& pwd );
    Customer( const Customer& customer );
    Customer( Customer&& customer );
    ~Customer(){
        --vipnum;
        record.clear();
    }

    Customer Customer::operator= ( Customer& obj );

    std::vector<Loan> getRecord() const { return this->record; }
    void newRecord( const Loan& loan ){
        record.push_back( loan );
        recnum = record.size();
    }
    void newRecord( const Book& book, const Date& date ){
        Loan loan( book, date, this->getName() );
        record.push_back( loan );
        recnum = record.size();
    }
    void deleteRecord( Loan& loan ){

        for ( auto iter = record.begin(); iter != record.end();  )
        {
            if(loan.getISBN() == iter->getISBN()){
                //  实际上erase掉的是同一个地址，不是指针本身
                /*auto iter_match = iter;*/
                //  注意这里的返回，是一个迭代器，指向被删除的元素的下一个元素，这样iter就不是野指针
                //  同时,重载Loan的==,可使用remove;
                iter = record.erase( iter );
            }
            else{
                ++iter; //  不erase才++. 这样就不会错.
            }
        }
    }
    void setRecord( std::vector<Loan> loan ){ record = loan; }
    void deleteRecord(){ this->record.clear(); }
    void setRecNum( size_t num ){ this->recnum = num; }
    size_t getRecNum(){ return recnum; }
    int getVipNum( ){ return Customer::vipnum; }
    void setVipNum( int n ){ Customer::vipnum = n; }

private:
    std::vector<Loan> record;
    size_t recnum{ 0 };
};

int Customer::vipnum = 0;

Customer::Customer( const Person& person, const ID& account) :
    Person( person ), ID( account ) {
    ++vipnum;
    recnum = record.size();
}

Customer::Customer( const std::string& name, const std::string& id, const std::string& pwd ) :
    Person( name ), ID( id, pwd )   {
    ++vipnum;
    setRecNum( record.size() );
}

Customer::Customer( const Customer& customer ) :
    Person( customer.getName() ),
    ID( customer.getID(), customer.getPWD() )   {
    ++vipnum;
    setRecord( customer.getRecord() );
    setRecNum(record.size());
}

Customer::Customer( Customer&& customer ) :
    Person( customer.getName() ),
    ID( customer.getID(), customer.getPWD())    {
    ++vipnum;

    setRecord( customer.getRecord() );
    setRecNum( customer.getRecNum() );

    customer.deleteRecord();
    customer.setRecNum( 0 );
}


Customer Customer::operator= ( Customer& obj )
{
    if ( this != &obj )
    {
        this->setName( obj.getName() );
        this->setAccount( obj.getID() , obj.getPWD() );
        setRecord( obj.getRecord() );
        setRecNum( obj.getRecNum() );
    }
    return *this;
}


#endif



