#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "id.h"

class Person{
public:
    Person() = default;
    Person( std::string name ){ this->name = name; }
    ~Person(){}
    void setName( std::string name ){ this->name = name; }
    std::string getName(){ return this->name; }
private:
    std::string name="Â·ÈË¼×";
};

class Customer:public Person{
public:
    Customer() = default;
    Customer( std::string id, std::string pwd , std::string name){
        this->account.setID( id, pwd );
        this->setName( name );
    }
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
