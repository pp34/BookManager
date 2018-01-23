#ifndef  TITLE_H
#define  TITLE_H

#include <iostream>
#include <iomanip>
#include <string>

class Title{
public:
    Title() = default;
    Title( const Title &title ) :
        bookName( title.bookName ), author( title.author ), ISBN( title.ISBN ){};
    Title( const std::string &bookname, const std::string &author, const std::string &isbn ):
    bookName( bookname ),author(author),ISBN(isbn){};
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

    inline std::string getAuthor() const {
        return this->author;
    }
    inline std::string getBookName() const {
        return this->bookName;
    }
    inline std::string getISBN() const {
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


