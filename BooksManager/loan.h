#ifndef  LOAN_H
#define  LOAN_H

#include <iostream>
#include <string>
#include "book.h"
#include "date.h"
#include "person.h"


class Loan{
public:
    Loan() = default;
    Loan(Book book, Customer customer, Date date){
        this->book = book;
        this->customer = customer;
        this->date = date;
    };
    ~Loan(){};

    void display(){ 
        std::cout << "Book's Information:\n"; 
        book.display();
        std::cout << "Customer's Information:\n";
        customer.display();
        std::cout << "Date's Information:\n";
        date.display();
    }
private:
    Book book;
    Customer customer;
    Date date;
};



#endif
