#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "id.h"

class Person{
public:
   // Person() = default;
    Person(const std::string &name ):name(name){}
    ~Person(){}
    void setName( const std::string &name ){ this->name = name; }
    inline std::string getName() const { return this->name; }
private:
    std::string name="Â·ÈË¼×";
};

class Customer:public Person{
public:
   // Customer() = default;
    Customer( const ID &account, const std::string &name ) : Person( name ),account( account ){}
    Customer( const std::string &id, const std::string &pwd , const std::string &name):
    Person( name ), account( id , pwd ){}
    ~Customer(){ 
        //std::cout << "A Customer had login out.\n"; 
    }
    void display(){
        std::cout << std::left << std::setw( 20 ) << "Customer's ID: " << std::right << std::setw( 20 ) << this->account.getID() << std::endl \
            << std::left << std::setw( 20 ) << "Customer's Name: " << std::right << std::setw( 20 ) << this->getName() << std::endl;
    }
private:
    ID account;
};


#endif
