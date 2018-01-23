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

    Reser( const Book &book, const Customer &customer, const Date &date, const unsigned int &num ) :
        book( book ), customer( customer ), date( date ), number( num ){}
    ~Reser(){};
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
