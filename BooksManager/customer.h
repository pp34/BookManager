#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "id.h"
#include "person.h"
//#include <iomanip>

class Customer :public Person, public ID{
public:
    Customer() = default;// { std::cout << "Customer Default Ctor.\n"; };
    
    Customer::Customer( const Person& person, const ID& account );
    Customer( const std::string& name, const std::string& id, const std::string& pwd );

    Customer( const Customer& customer );
    Customer( const Customer&& customer );

    Customer& Customer::operator= ( Customer& obj );

    ~Customer(){}

    void display(){
        std::cout << std::left << std::setw( 20 ) << "Customer's ID: " << std::right << std::setw( 20 ) << this->getID() << std::endl \
            << std::left << std::setw( 20 ) << "Customer's Name: " << std::right << std::setw( 20 ) << this->getName() << std::endl;
    }
private:
   // ID account;
};


Customer::Customer( const Person& person, const ID& account ) : Person( person ), ID( account ){}
Customer::Customer( const std::string& name, const std::string& id, const std::string& pwd ) : Person( name ), ID( id, pwd ){}

Customer::Customer( const Customer& customer ) : Person( customer.getName() ), ID( customer.getID(), customer.getPWD() ){}
Customer::Customer( const Customer&& customer ) : Person( customer.getName() ), ID( customer.getID(), customer.getPWD()){}


Customer& Customer::operator= ( Customer& obj )
{
    if ( this != &obj )
    {
        this->setName( obj.getName() );
        this->setAccount( obj.getID() ,obj.getPWD());
    }
   // std::cout << "Customer Copy Operator.\n";
    return *this;
}



#endif



