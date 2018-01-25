#ifndef  BOOK_H
#define  BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

#include "title.h"

class Book :public Title{
public:
    Book() = default;
    explicit Book( const Book& );
    explicit Book( const std::string& bookname, const std::string& author, const std::string& isbn, const double price ) ;
    explicit Book( const Title& title, const double price );
    //Book( const Book&& book ) noexcept;
    ~Book() = default;

    Book& Book::operator=( Book& obj );
   // Book& Book::operator=( Book&& obj );

    void display(){
        title.display();
        std::cout << std::left << std::setw( 20 ) << "price: " << std::right << std::setw( 20 ) <<this->price << std::endl;
    }
private:
    Title title;
    double price{ 0.0 };

};

Book::Book( const Book& book):title( book.title ), price( price ){}
Book::Book( const std::string& bookname, const std::string& author, const std::string& isbn, const double price ) :
    title( bookname ,  author ,  isbn  ), price( price ){}
Book::Book( const Title& title, const double price ) : title( title ), price( price ){}
//Book::Book( const Book&& book ) :title( std::move( book.title ) ), price( book.price ){}




Book& Book::operator=( Book& obj ){
    if ( this != &obj )
    {
        title = obj.title ;
        price = obj.price;
    }
    return *this;
}

//Book& Book::operator=( Book&& obj ){
//    if ( this != &obj )
//    {
//        title = std::move( obj.title );
//        price = obj.price;
//    }
//    return *this;
//}








#endif



