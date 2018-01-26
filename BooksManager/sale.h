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
    Sale(){ std::cout << "Sale Default Ctor.\n"; };
    Sale( const Book book, const Customer customer, const Date date, const double price ) :
        book( book ), customer( customer ), date( date ), price( price ){
        std::cout << "Sale Normal Ctor.\n";
    }
    Sale( const Sale& sale ) :
        book( sale.book ), customer( sale.customer ), date( sale.date ), price( sale.price ){
        std::cout << "Sale Copy Ctor.\n";
    }
    Sale( const Sale&& sale ) :
        book( std::move( sale.book ) ), customer( std::move( sale.customer ) ), date( std::move( sale.date ) ), price( sale.price ){
        std::cout << "Sale Move Ctor.\n";
    }
    ~Sale(){};

    Sale& Sale::operator=( Sale& obj ){
        if ( this != &obj )
        {
            book = obj.book ;
            customer = obj.customer;
            date = obj.date;
            price = obj.price;
        }
        std::cout << "Sale Copy Operator.\n";
        return *this;
    }
    Sale& Sale::operator=( Sale&& obj ){
        if ( this != &obj )
        {
            book = std::move( obj.book );
            customer = std::move( obj.customer );
            date =  obj.date ;
            price = obj.price;
        }
        std::cout << "Sale Move Operator.\n";
        return *this;
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

