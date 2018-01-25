#ifndef  LOAN_H
#define  LOAN_H

#include <iostream>
#include <string>
#include "book.h"
#include "date.h"
#include "person.h"


class Loan:public Book, public Customer,public Date{
public:
    Loan() = default;
    
    explicit Loan( const Loan& loan) :
        book( loan.book ), customer( loan.customer ), date( loan.date ){}
    explicit Loan( const Book& book, const Customer& customer, const Date& date ) :
       book( book ),customer( customer ),date( date ){}  
    //Loan( const Loan&& loan ):
    //    book( std::move( loan.book ) ), customer( std::move( loan.customer ) ), date( std::move( loan.date ) ){}
    //Loan(const Book&& book, const Customer&& customer, const Date&& date):
    //    book( std::move(book) ),customer( std::move(customer) ),date( std::move(date) ){}  
    ~Loan(){}

    Loan& Loan::operator=( Loan& obj );
    Loan& Loan::operator=( Loan&& obj );

    void display(){ 
        std::cout << "Book's Information:\n"; 
        book.display();
        std::cout << "Customer's Information:\n";
        customer.display();
        std::cout << "Date's Information:\n";
        date.display();
    }
private:
    Book book;
    Customer customer;
    Date date;
};


Loan& Loan::operator=( Loan& obj ){
    if ( this != &obj )
    {
        book = ( obj.book );
        customer = ( obj.customer );
        date = ( obj.date );
    }return *this;
}

Loan& Loan::operator=( Loan&& obj ){
    if ( this != &obj )
    {
        book = std::move( obj.book );
        customer = std::move( obj.customer );
        date = ( obj.date );
    }return *this;
}

#endif
