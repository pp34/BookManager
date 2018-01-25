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
    Date()=default;
    
    explicit Date( const unsigned int& year, const Month& month );

    //Date( const Date&& date ) noexcept;
    //Date( const unsigned int&& year, const Month&& month ) noexcept;

    ~Date() = default;

    //Date Date::operator=( Date& obj )=default;
    Date& Date::operator=( Date& obj );

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


Date::Date( const unsigned int& year, const Month& month ) :year( year ), month( month ) {}

//Date::Date( const Date&& date ) :year( date.year ), month( date.month ){}
//Date::Date( const unsigned int&& year, const Month&& month ) :year( year ), month( month ){}

Date& Date::operator=( Date& obj ){
    if ( this != &obj )
    {
        year = obj.year;
        month = obj.month;
    }return *this;
}

#endif



