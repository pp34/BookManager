#ifndef  DATE_H
#define  DATE_H

#include <iostream>
#include <string>

typedef enum{
    Jan = 1, Febr, Mar,
    April, May, June,
    July, Aug, Stemp,
    Oct, Nov, Dec
} Month;

class Date{
public:
    //Date()=default;
    Date( const unsigned int year, const Month month ) :year( year ), month( month ){}
    ~Date(){};
    void setYear( unsigned int year ){ this->year = year; }
    void setMonth( Month month ){ this->month = month; }
    inline unsigned int getYear() const { return this->year; }
    inline Month getMonth() const { return this->month; }
    void display(){
        std::cout << std::left << std::setw( 20 ) <<"Date: " << std::right<< std::setw(20-4) <<this->getYear() \
            << " - " << this->getMonth() << std::endl;
    }
private:
    unsigned int year=2018;
    Month month = Month::Jan;
};




#endif



