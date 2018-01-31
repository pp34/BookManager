#ifndef  LOAN_H
#define  LOAN_H

#include <iostream>
#include <string>
#include "book.h"
#include "date.h"


class Loan :public Book, public Date{
public:
    static int loannum;
    Loan(){ ++loannum; }
    Loan( const Book& book, const Date& date, const std::string& who );
    Loan( const Loan& loan );
    ~Loan(){ --loannum; }

    Loan& Loan::operator=( Loan& obj );
    int getLoanNum(){ return loannum; }
    std::string getWho() const { return who; }
    void setWho( std::string w ){ who = w; }

private:
    std::string who;
};
int Loan::loannum = 0;
Loan::Loan( const Book& book, const Date& date , const std::string& who ) :
    Book( book ), Date( date ),who( who ) { ++loannum; }
Loan::Loan( const Loan& loan ) :
    Book( loan.getBookName(), loan.getAuthor(), loan.getISBN(), loan.getPrice(),loan.getNum() ),
    Date( loan.getYear(), loan.getMonth() ),
    who(loan.getWho())
    { ++loannum;}


Loan& Loan::operator=( Loan& obj ){
    if ( this != &obj )
    {
        this->setBookName(obj.getBookName()) ;
        this->setAuthor( obj.getAuthor() );
        this->setISBN( obj.getISBN() );
        this->setPrice( obj.getPrice() );
        this->setDate( obj.getYear(), obj.getMonth() );
        this->setWho( obj.getWho() );
    }
    return *this;
}

#endif
