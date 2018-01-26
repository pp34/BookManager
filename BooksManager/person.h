#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "id.h"
#include <iomanip>

class Person
{
public:
    Person() = default;// { std::cout << "Person Default Ctor.\n"; }
    Person( const Person& person);
    Person( const std::string& name );
    Person( const Person&& person );
    
    ~Person(){}

    Person& Person::operator= ( Person& obj );
    Person& Person::operator= ( Person&& obj );

    void setName( const std::string &name ){ this->name = name; }
    inline std::string getName() const { return this->name; }
    void printName() const { std::cout << this->getName() << std::endl; }

private:
    std::string name="Â·ÈË¼×";
};



Person::Person( const Person& person ):name( person.name ){ }
Person::Person( const std::string& name ) :name( name ){  }
Person::Person( const Person&& person ) :name( std::move( person.name ) ){  }




Person& Person::operator= ( Person& obj )
{
    if ( this != &obj )
    {
        name = obj.name;
    }
    //std::cout << "Person Copy Operator.\n";
    return *this;
}

Person& Person::operator= ( Person&& obj )
{
    if ( this != &obj )
    {
        name = obj.name;
    }
    //std::cout << "Person Move Operator.\n";
    return *this;
}



#endif
