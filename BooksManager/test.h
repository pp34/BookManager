#ifndef _TEST_H
#define _TEST_H

#include <iostream>
#include <iomanip>

std::string ctor_type( int type ){
    std::string str;
    if ( type == 0 )
    {
        str = "һ�㹹�캯��";
    }
    else if ( type == 1 )
    {
        str = "�������캯��";
    }
    else if ( type == 2 )
    {
        str = "�ƶ����캯��";
    }
    else if ( type == 3 ){
        str = "=���������--����";
    }
    else if ( type == 4 )
    {
        str = "=���������--�ƶ�";
    }
    else if ( type == 5 )
    {
        str = "Ĭ�Ϲ��캯��";
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
        << "��������" << std::endl;
}


#endif