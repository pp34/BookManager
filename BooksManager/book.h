#ifndef  BOOK_H
#define  BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

#include "title.h"

class Book :public Title{
public:
    Book() = default;   // { std::cout << "Book Default Ctor.\n"; }
    Book( const std::string bookname, const std::string author, const std::string isbn, const double price );
    Book( const Title& title, const double price );
    Book( const Book& book );
    Book( const Book&& book ) ;

    ~Book() = default;

    Book& Book::operator=( Book& obj );
   // Book& Book::operator=( Book&& obj );

    double getPrice() const { return price; }
    void setPrice( double p ){ price = p; }

    void display(){
        //title.display();
        std::cout << std::left << std::setw( 20 ) << "price: " << std::right << std::setw( 20 ) << std::setprecision( 4 ) << getPrice() << std::endl;
        //std::cout << price << std::endl;
    }
private:
    double price{ 0.0 };

};
Book::Book( const std::string bookname, const std::string author, const std::string isbn, const double price ) :
    Title( bookname, author, isbn ), price( price ){}
Book::Book( const Title& title, const double price ) : Title( title ), price( price ){}

Book::Book( const Book& book) : Title( book.getBookName(), book.getAuthor(), book.getISBN()), price( book.getPrice() ){}
Book::Book( const Book&& book ) : Title( book.getBookName(), book.getAuthor(), book.getISBN() ), price( book.getPrice() ){}

Book& Book::operator=( Book& obj ){
    if ( this != &obj )
    {
        this->setBookName( obj.getBookName() );
        this->setAuthor( obj.getAuthor() );
        this->setISBN( obj.getISBN() );
        this->setPrice(obj.getPrice());
    }
    //std::cout << "Book Copy Operator.\n";
    return *this;
}







#endif



