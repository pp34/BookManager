#ifndef  LOAN_H
#define  LOAN_H

#include <iostream>
#include <string>
#include "book.h"
#include "date.h"
#include "person.h"


class Loan{
public:
   // Loan() = default;
    Loan(const Book &book, const Customer &customer, const Date &date):
    book(book),customer(customer),date(date){}  //  编译器自己执行的拷贝
                                                //  相当于对对象的每个成员执行拷贝
                                                //  调用编译器隐式生成的默认拷贝构造函数
    ~Loan(){}

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
