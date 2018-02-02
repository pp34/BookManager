#ifndef _TEST_H
#define _TEST_H

#include <iostream>
#include <iomanip>

std::string ctor_type( int type ){
    std::string str;
    if ( type == 0 )
    {
        str = "一般构造函数";
    }
    else if ( type == 1 )
    {
        str = "拷贝构造函数";
    }
    else if ( type == 2 )
    {
        str = "移动构造函数";
    }
    else if ( type == 3 ){
        str = "=运算符重载--拷贝";
    }
    else if ( type == 4 )
    {
        str = "=运算符重载--移动";
    }
    else if ( type == 5 )
    {
        str = "默认构造函数";
    }
    else;
    return str;
}

void printCtorType( std::string tmp, std::string str ){
    std::cout << std::left << std::setw( 10 )
        << tmp << ':';
    std::cout << std::left << std::setw( 10 )
        << str << std::endl;
}

void printDtor( std::string tmp ){
    std::cout << std::left << std::setw( 10 )
        << tmp << ':';
    std::cout << std::left << std::setw( 10 )
        << "析构函数" << std::endl;
}


#endif