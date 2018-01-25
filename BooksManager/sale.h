#ifndef  SALE_H
#define  SALE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "book.h"
#include "person.h"
#include "date.h"

class Sale{
public:
    Sale() = delete;
    Sale( const Sale& ) = delete;

    Sale( const Sale&& sale ) :
        book( std::move( sale.book ) ), customer( std::move( sale.customer ) ), date( std::move( sale.date ) ), price( sale.price ){}
    Sale ( const Book&& book, const Customer&& customer, const Date&& date, const double &price):
        book( std::move(book) ),customer( std::move( customer ) ),date( std::move( date ) ),price( price ){}


    ~Sale(){};


    Sale& Sale::operator=( Sale&& obj ){
        if ( this != &obj )
        {
            book = std::move( obj.book );
            customer = std::move( obj.customer );
            date =  obj.date ;
            price = obj.price;
        }return *this;
    }
    void display(){
        Sale::book.display();
        Sale::customer.display();
        Sale::date.display();
        std::cout << std::left << std::setw( 20 ) << "price: " << std::right << std::setw( 20 ) << this->price << std::endl;
    }
private:
    Book book;
    Customer customer;
    Date date;
    double price{ 0.0 };

};



#endif

