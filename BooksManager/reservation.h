#ifndef  RESERVATION_H
#define  RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>

#include "book.h"
#include "person.h"
#include "date.h"

class Reser{
public:
    Reser(){ std::cout << "Reser Default Ctor.\n"; };
    Reser( const Book& book, const Customer& customer, const Date& date, const unsigned int num ) :
        book( book ), customer( customer ), date( date ), number( num ){
        std::cout << "Reser Normal Ctor.\n";
    }
    Reser( const Reser& reser ) :
        book( reser.book ), customer( reser.customer ), date( reser.date ), number( reser.number ){
        std::cout << "Reser Copy Ctor.\n";
    }
    Reser( const Reser&& reser ) :
        book( std::move( reser.book ) ), customer( std::move( reser.customer ) ), date( std::move( reser.date ) ), number( reser.number ){
        std::cout << "Reser Move Ctor.\n";
    }
    ~Reser(){};

    Reser& Reser::operator=( Reser& obj ){
        if ( this != &obj )
        {
            book = obj.book ;
            customer = obj.customer;
            date = ( obj.date );
            number = obj.number;
        }
        std::cout << "Reser Copy Operator.\n";
        return *this;
    }
    Reser& Reser::operator=( Reser&& obj ){
        if ( this != &obj )
        {
            book = std::move( obj.book );
            customer = std::move( obj.customer );
            date = ( obj.date );
            number = obj.number;
        }
        std::cout << "Reser Move Operator.\n";
        return *this;
    }
    void display(){
        Reser::book.display();
        Reser::customer.display();
        Reser::date.display();
        std::cout << std::left << std::setw( 20 ) << "number: " << std::right << std::setw( 20 ) << this->number << std::endl;
    }
private:
    Book book;
    Customer customer;
    Date date;
    unsigned int number{ 0 };
};



#endif
