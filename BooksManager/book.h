#ifndef  BOOK_H
#define  BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

#include "title.h"

class Book:public Title{
public:
    //Book() = default;
    Book( const Title &title , const double &price ):title( title ),price(price){
      //  std::cout << " 1 " << std::endl;
    }
    Book( const std::string &bookname, const std::string &author, const std::string &isbn , const double &price ):
        title( bookname, author, isbn ), price( price ){
       // std::cout << " 2 " << std::endl;
    }
    ~Book(){};
    void display(){
        title.display();
        std::cout << std::left << std::setw( 20 ) << "price: " << std::right << std::setw( 20 ) <<this->price << std::endl;
    }
private:
    Title title;
    double price{ 0.0 };

};



#endif



