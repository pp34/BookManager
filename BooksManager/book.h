#ifndef  BOOK_H
#define  BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

#include "title.h"

class Book{
public:
    Book() = default;
    Book( Title title ,double price){
        this->title = title;
        this->price = price;
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



