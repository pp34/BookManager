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
    //Book() = default;
    Sale ( const Book &book, const Customer &customer, const Date &date, const double &price):
       book( book ),customer( customer ),date( date ),price( price ){}
    ~Sale(){};
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

