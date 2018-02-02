#ifndef  DATA_H
#define  DATA_H

#include <iostream>
#include <vector>
#include <string>

#include "customer.h"
#include "book.h"

class Clerk;

struct BookList{
    std::vector<Book> book;
    int total{ 0 };
    void clear();
};

struct SalesData{
    std::vector<Customer> vip;
    //std::vector<Loan> loan;
    std::vector<Clerk> clerk;
    void clear();
};

void BookList::clear(){
    if(!book.empty())
        book.clear();
}

void SalesData::clear(){
    if ( !vip.empty() )
        vip.clear();
    if ( !clerk.empty() )
        clerk.clear();
}


#endif



