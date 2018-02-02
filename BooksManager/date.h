#ifndef  DATE_H
#define  DATE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Date{
public:
    //friend std::ostream& printDate( std::ostream&, const Date& date );

    Date() = default;
    Date( const unsigned int year, const unsigned int month );
    Date( const Date& date );
    ~Date() = default;

    Date& Date::operator=( Date& obj );

    void setDate( unsigned int year , unsigned int month ){
        this->year = year;
        this->month = month;
    }
    void setYear( unsigned int year ){ this->year = year; }
    void setMonth( unsigned int month ){ this->month = month; }
    unsigned int getYear() const { return this->year; }
    unsigned int getMonth() const { return this->month; }
    virtual void printDate( std::ostream& os ){
        os << std::left << std::setw( 20 ) << "Date: ";
        os << std::right << std::setw( 20 );
        do_display( os );
    }
private:
    void do_display( std::ostream& os )const{
        std::stringstream buff;
        std::string tmp;
        buff << year << "-" << month;
        buff >> tmp;
        os << tmp << std::endl;
    }
    unsigned int year=2018;
    unsigned int month = 1;
};


Date::Date( const unsigned int year, const unsigned int month ) :year( year ), month( month ) {  }
Date::Date( const Date& date ) :year( date.year ), month( date.month ){  }

Date& Date::operator=( Date& obj ){

    year = obj.year;
    month = obj.month;

    return *this;
}

//std::ostream& printDate( std::ostream& os, const Date& date ){
//    os << std::left << std::setw( 20 ) << "Date: "
//        << std::right << std::setw( 20 - 4 ) << date.getYear()
//        << " - " << date.getMonth() << std::endl;
//    return os;
//}

#endif



