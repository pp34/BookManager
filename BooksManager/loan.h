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
    book(book),customer(customer),date(date){}  //  �������Լ�ִ�еĿ���
                                                //  �൱�ڶԶ����ÿ����Աִ�п���
                                                //  ���ñ�������ʽ���ɵ�Ĭ�Ͽ������캯��
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
