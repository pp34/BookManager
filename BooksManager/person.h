#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "id.h"
#include <iomanip>

class Person
{
public:
    Person() = default;
    explicit Person( const Person& );
    explicit Person( const std::string &name );
    //Person( const Person&& person );
    
    ~Person(){}

    Person& Person::operator= ( Person& obj );
    Person& Person::operator= ( Person&& obj );
    void setName( const std::string &name ){ this->name = name; }
    inline std::string getName() const { return this->name; }
    void printName() const { std::cout << this->getName() << std::endl; }
private:
    std::string name="Â·ÈË¼×";
};


class Customer:public Person{
public:
    Customer() = default;

    explicit Customer( const Customer& );
    explicit Customer::Customer( const Person& person, const ID& account );
    explicit Customer( const std::string& name, const std::string& id, const std::string& pwd );

    //Customer( const Customer&& customer ) noexcept;
    //Customer( const Person&& person, const ID&& account ) noexcept;

    Customer& Customer::operator= ( Customer& obj );
    Customer& Customer::operator= ( Customer&& obj );
    ~Customer(){}
    void display(){
        std::cout << std::left << std::setw( 20 ) << "Customer's ID: " << std::right << std::setw( 20 ) << this->account.getID() << std::endl \
            << std::left << std::setw( 20 ) << "Customer's Name: " << std::right << std::setw( 20 ) << this->getName() << std::endl;
    }
private:
    ID account;
};

Person::Person( const Person& person ):name( person.name ){}
Person::Person( const std::string& name ) :name( name ){}
//Person::Person( const Person&& person ) :name( std::move( person.name ) ){}

Customer::Customer( const Customer& customer ) : Person( customer.getName() ), account( customer.account  ){}
Customer::Customer( const Person& person, const ID& account ):Person( person ), account( account ){}
Customer::Customer( const std::string& name, const std::string& id, const std::string& pwd ) :Person( name ), account( id, pwd ){}
//Customer::Customer( const Customer&& customer ) :Person( customer.getName() ), account( std::move( customer.account ) ){}
//Customer::Customer( const Person&& person, const ID&& account ) :Person( std::move(person) ), account( std::move(account) ){}

Person& Person::operator= ( Person& obj )
{
    //std::cout << "move =" << std::endl;
    if ( this != &obj )
    {
        name = obj.name;
    }
    return *this;
}

Person& Person::operator= ( Person&& obj )
{
    //std::cout << "move =" << std::endl;
    if ( this != &obj )
    {
        name = obj.name;
    }
    return *this;
}

Customer& Customer::operator= ( Customer& obj )
{
    //std::cout << "move =" << std::endl;
    if ( this != &obj )
    {
        this->setName( obj.getName() );
        this->account = ( obj.account );
    }
    return *this;
}

Customer& Customer::operator= ( Customer&& obj )
{
    //std::cout << "move =" << std::endl;
    if ( this != &obj )
    {
        this->setName( obj.getName() );
        this->account = std::move( obj.account );
    }
    return *this;
}




#endif
