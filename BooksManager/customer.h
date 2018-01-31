#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "id.h"
#include "person.h"
#include "loan.h"


class Customer :public Person, public ID, public Loan{
public:
    static int vipnum;
    //friend class clerk;
    Customer() {
        ++vipnum; 
        recnum = record.size();
    }
    
    Customer( const Person& person, const ID& account,const Loan& loan );
    Customer( const std::string& name, const std::string& id, const std::string& pwd );
    Customer( const Customer& customer );
    Customer( const Customer&& customer );
    ~Customer(){ 
        --vipnum; 
        record.clear();
    }

    Customer& Customer::operator= ( Customer& obj );

    std::vector<Loan> getRecord(){ return this->record; }
    void newRecord( const Loan& loan){
        record.push_back( loan );
        recnum = record.size();
    }
    void newRecord( const Book& book, const Date& date ){
        record.push_back( Loan(book,date,this->getName()) );
        recnum = record.size();
    }
    void setRecNum( size_t num ){ this->recnum = num; }
    size_t getRecNum(){ return recnum; }

private:
    std::vector<Loan> record;
    size_t recnum{ 0 };
};

int Customer::vipnum = 0;

Customer::Customer( const Person& person, const ID& account, const Loan& loan ) : 
    Person( person ), ID( account ), Loan(loan) { 
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
    setRecNum(record.size());
}

Customer::Customer( const Customer&& customer ) : 
    Person( customer.getName() ), 
    ID( customer.getID(), customer.getPWD())    { 
    ++vipnum; 
    setRecNum( record.size() );
}


Customer& Customer::operator= ( Customer& obj )
{
    if ( this != &obj )
    {
        this->setName( obj.getName() );
        this->setAccount( obj.getID() ,obj.getPWD());
        setRecNum( obj.getRecNum() );
    }
    return *this;
}


#endif



