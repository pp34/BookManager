#ifndef  TITLE_H
#define  TITLE_H

#include <iostream>
#include <string>

class Title{
public:
    Title() = default;
    Title( std::string bookname, std::string author,std::string isbn ){
        this->setBookName( bookname );
        this->setAuthor( author );
        this->setISBN( isbn );
    };
    ~Title(){};

 /*   Title* findTitle( std::string isbn );
    Title* findTitle( std::string bookname );
*/
    //Title* addBook(Book::title);
    //Title* removeBook( Book::title );

    void setAuthor( std::string author ){
        this->author = author;
    }
    void setBookName( std::string bookname ){
        this->bookName = bookname;
    }
    void setISBN( std::string isbn ){
        this->ISBN = isbn;
    }

    inline std::string getAuthor(){
        return this->author;
    }
    inline std::string getBookName(){
        return this->bookName;
    }
    inline std::string getISBN(){
        return this->ISBN;
    }

    void display(){
        std::cout << std::left << std::setw( 20 ) <<"Book's Name: " <<std::right << std::setw( 20 )<< this->getBookName() << std::endl \
            << std::left << std::setw( 20 ) << "Book's Author: " << std::right << std::setw( 20 ) << this->getAuthor() << std::endl \
            << std::left << std::setw( 20 ) << "Book's ISBN: " << std::right << std::setw( 20 ) << this->getISBN() << std::endl;
    }

private:
    std::string bookName;
    std::string ISBN;
    std::string author;
};



#endif


