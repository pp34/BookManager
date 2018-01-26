#ifndef  LOAN_H
#define  LOAN_H

#include <iostream>
#include <string>
#include "book.h"
#include "date.h"
#include "person.h"
#include "customer.h"

class Loan:public Book, public Customer,public Date{
public:
    Loan() = default;
    Loan( const Book& book, const Customer& customer, const Date& date );
    Loan( const Loan& loan );
    Loan( const Loan&& loan );
    ~Loan(){}

    Loan& Loan::operator=( Loan& obj );

private:

};

Loan::Loan( const Book& book, const Customer& customer, const Date& date ) :
    Book( book ), Customer( customer ), Date( date ){}
Loan::Loan( const Loan& loan ) :
    Book( loan.getBookName(),loan.getAuthor(),loan.getISBN(),loan.getPrice() ), 
    Customer( loan.getName(),loan.getID(),loan.getPWD() ), 
    Date( loan.getYear(),loan.getMonth() ){}

Loan::Loan( const Loan&& loan ) :
    Book( loan.getBookName(), loan.getAuthor(), loan.getISBN(), loan.getPrice() ),
    Customer( loan.getName(), loan.getID(), loan.getPWD() ),
    Date( loan.getYear(), loan.getMonth() ){}

Loan& Loan::operator=( Loan& obj ){
    if ( this != &obj )
    {
        this->setBookName(obj.getBookName()) ;
        this->setAuthor( obj.getAuthor() );
        this->setISBN( obj.getISBN() );
        this->setPrice( obj.getPrice() );

        this->setName( obj.getName() );
        this->setAccount( obj.getID(), obj.getPWD() );

        this->setDate( obj.getYear(), obj.getMonth() );
       
    }
    std::cout << "Loan Copy Operator.\n";
    return *this;
}

#endif
