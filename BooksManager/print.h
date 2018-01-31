#ifndef  PRINT_H
#define  PRINT_H


#include <iostream>
#include <algorithm>
#include <iomanip>

#include "data.h"
#include "book.h"
#include "customer.h"
#include "db.h"

#ifndef _NAME_PP
#define _NAME_PP


namespace pp
{
int sta{ 0 };
std::string page;

    void hall();
    void borrow();
    void reserv();
    void login_vips( SalesData& salesdata );
    void login_clerk( SalesData& salesdata );
    
    void manager( bool root );

    void find_bookName( BookList& bookdata );
    void find_isbn( BookList& bookdata );
    void add_book( BookList& bookdata );
    void delete_book( BookList& bookdata );
    void modify_book( BookList& bookdata );

    void tips();
    void error();
    void exit( BookList& bookdata, SalesData& salesdata ){ saveAllData( bookdata, salesdata ); }
    void what_is_sta( BookList& bookdata, SalesData& salesdata );
    void get_sta( std::istream& in );
    void set_sta( std::string p, int sta ){ pp::page = p; pp::sta = sta; }

    void printLoan( SalesData& salesdata );
    void printAllLoan( SalesData& salesdata );

    void printCustomer(const Customer& cus);
    void printBook( const Book& book );
    void printTitle( const Title& title );
    void printAllBook( BookList& bookdata );


};


void pp::what_is_sta( BookList& bookdata, SalesData& salesdata ){

    while ( 1 )
    {
        pp::get_sta( std::cin );
        std::cout << "\n\n";
        // 前两个交互页
        if ( pp::page == "hall" )
        {
            switch ( pp::sta )
            {
                case 1:pp::login_vips( salesdata ); break;
                case 2:pp::login_clerk( salesdata ); break;
                case 3:pp::exit( bookdata, salesdata ); break;
                default:pp::error(); break;
            }
        }
        else if( pp::page == "manager_root" ){
            switch ( pp::sta )
            {
                case 1:pp::find_bookName( bookdata ); break;
                case 2:pp::find_isbn( bookdata ); break;
                case 3:pp::printAllBook( bookdata ); pp::borrow(); break;
                case 4:pp::hall(); break;
                case 5:pp::exit( bookdata, salesdata ); break;
                default:pp::error(); break;
            }
        }
        else if ( pp::page == "manager_no_root" ) {
            switch ( pp::sta )
            {
                case 1:pp::borrow(); break;
                case 2:pp::reserv(); break;
                case 3:break;//chazhao
                case 4:pp::printAllBook( bookdata ); 
                       pp::manager( FALSE ); 
                       break;
                case 5:pp::hall(); break;
                case 6:pp::exit( bookdata, salesdata ); break;
                default:pp::error(); break;
            }
        }
        // 现在开始是功能页
        else if ( pp::page == "borrow" )
        {
            switch ( pp::sta )
            {
                case 1:pp::find_bookName( bookdata ); break;
                case 2:pp::find_isbn( bookdata ); break;
                case 3:pp::printAllBook( bookdata ); pp::borrow(); break;
                case 4:pp::hall(); break;
                case 5:pp::exit( bookdata, salesdata ); break;
                default:pp::error(); break;
            }
        }
        else {}
    }
}

void pp::reserv(){
    // printLoan
    std::cout << "输入所归还的书籍编号: _\b";
    pp::tips();
    pp::set_sta( "reserv", 0 );
}
void add_book( BookList& bookdata ){}
void delete_book( BookList& bookdata ){}
void modify_book( BookList& bookdata ){}
void printLoan( SalesData& salesdata ){}
void printAllLoan( SalesData& salesdata ){}

void pp::manager( bool root ){
    if ( root )
    {
        std::cout << "1、添加书目" << std::endl;
        std::cout << "2、删除书目" << std::endl;
        std::cout << "3、更改书目" << std::endl;
        std::cout << "4、借出书目" << std::endl;
        std::cout << "5、返回" << std::endl;
        std::cout << "6、离开" << std::endl;
        pp::tips();
        pp::set_sta( "manager_root", 0 );
    }
    else
    {
        std::cout << "1、借阅书目" << std::endl;
        std::cout << "2、归还书目" << std::endl;
        std::cout << "3、在借书目" << std::endl;
        std::cout << "4、现有书目" << std::endl;
        std::cout << "5、返回" << std::endl;
        std::cout << "6、离开" << std::endl;
        pp::tips();
        pp::set_sta( "manager_no_root", 0 );
    }
}

void pp::hall(){

    std::cout << "1、读者维护入口" << std::endl;
    std::cout << "2、管理员维护入口" << std::endl;
    std::cout << "3、离开" << std::endl;
    pp::tips();
    pp::set_sta( "hall", 0 );
}

void pp::borrow(){
    std::cout << "1、输入书名" << std::endl;
    std::cout << "2、输入ISBN" << std::endl;
    std::cout << "3、已有书籍" << std::endl;
    std::cout << "4、返回" << std::endl;
    std::cout << "5、离开" << std::endl;
    pp::tips();
    pp::set_sta( "borrow", 0 );
}


void pp::find_bookName( BookList& bookdata ){

    __int64 dist{ -1 };
    std::string tmp;
    std::cout << "书名：" << std::endl;
    std::cin >> tmp;
    auto iter = bookdata.book.begin();
    while(iter!= bookdata.book.end() ){
        if ( iter->getBookName() == tmp )
        {
            auto iter_next = iter;
            dist = std::distance( bookdata.book.begin(), iter_next );
            std::cout << "Here is the book in: NO. \t" << dist + 1 << std::endl;
            std::cout 
                << std::setw(20) 
                << std::right
                << ( iter_next->getBookName() )
                << '\t';
            std::cout 
                << std::setw( 20 )
                << std::right
                << ( iter_next->getISBN() ) 
                << '\t';
            std::cout 
                << std::setw( 20 )
                << std::right
                << ( iter_next->getAuthor() ) 
                << '\t';
            std::cout 
                << std::setw( 20 )
                << std::right
                << ( iter_next->getPrice() ) 
                << '\t';
            std::cout 
                << std::setw( 20 )
                << std::right
                << ( iter_next->getNum() ) 
                << '\n';
        }
        else;
        ++iter;
    }
    if( ( iter == bookdata.book.end() ) && ( dist==-1 ) ){
        std::cout << "Error: There is not a book named, " << tmp << " here.\n\n";
        pp::hall();
    }   
    else{
        std::cout << "More books wanna to find? Y/N :_\b";
    }
    std::cin >> tmp;
    if(tmp == "Y"){ 
        pp::find_bookName( bookdata ); 
        pp::page = "find_bookName";
    }
    else {
        pp::borrow();
    }
    pp::sta = 0;
}

void pp::find_isbn( BookList& bookdata ){

    __int64 dist{ -1 };
    std::string tmp;
    std::cout << "ISBN：" << std::endl;
    std::cin >> tmp;
    auto iter = bookdata.book.begin();
    while ( iter != bookdata.book.end() )
    {
        if ( iter->getISBN() == tmp )
        {
            auto iter_match = iter;
            dist = std::distance( bookdata.book.begin(), iter_match );
            std::cout << "Here is the book in: NO. \t" << dist + 1 << std::endl;
            std::cout
                << std::setw( 20 )
                << std::right
                << ( iter_match->getBookName() )
                << '\t';
            std::cout
                << std::setw( 20 )
                << std::right
                << ( iter_match->getISBN() )
                << '\t';
            std::cout
                << std::setw( 20 )
                << std::right
                << ( iter_match->getAuthor() )
                << '\t';
            std::cout
                << std::setw( 20 )
                << std::right
                << ( iter_match->getPrice() )
                << '\t';
            std::cout
                << std::setw( 20 )
                << std::right
                << ( iter_match->getNum() )
                << '\n';
        }
        else;
        ++iter;
    }
    if ( ( iter == bookdata.book.end() ) && ( dist == -1 ) )
    {
        std::cout << "Error: There is not a book named, " << tmp << " here.\n\n";
        pp::borrow();
    }
    else
    {
        std::cout << "More books wanna to find? Y/N :_\b";
    }
    std::cin >> tmp;
    if ( tmp == "Y" || tmp == "y" )
    {
        pp::find_isbn( bookdata );
        pp::page = "find_isbn";
    }
    else
    {
        pp::borrow();
    }
    pp::sta = 0;
}



void pp::login_vips( SalesData& salesdata ){

    __int64 dist{ -1 };
    std::string tmp1, tmp2;

    std::cout << "\n请输入账号: _____\b\b\b\b\b";
    std::cin >> tmp1;

    std::cout << "\n请输入密码: ______\b\b\b\b\b\b";
    std::cin >> tmp2;

    auto iter = salesdata.vip.begin();
    while( iter!= salesdata.vip.end() ){
        if( tmp1 == ( iter->getID() ) ){
            auto iter_match = iter;
            dist = std::distance( salesdata.vip.begin(), iter_match );
            std::cout << "Here is the VIPS in: NO. \t" << dist + 1 << std::endl;
            std::cout << "ID is :\n";
            std::cout
                << std::setw( 20 )
                << std::right
                << ( iter_match->getID() )
                << '\t';
            if(tmp2 == ( iter_match->getPWD() )){
                std::cout << "Welcome!\n\n";
                pp::manager( FALSE );
            }
            else{
                std::cout << "Error: There is a wrong accout PWD  " << tmp2 << " here.\n\n";
                std::cout << "Again? Y/N : _\b";
                std::cin >> tmp2;
                if ( tmp2 == "Y" || tmp2 == "y" )
                {
                    login_vips( salesdata );
                    pp::page = "login_vips";
                    pp::sta = 0;
                }
                else
                    pp::hall();
            }
        }
        else;
        ++iter;
        if( ( iter == salesdata.vip.end() ) && ( dist == -1 ) ){
            std::cout << "Error: There is a wrong accout ID:  " << tmp1 << " here.\n\n";
            pp::hall();
        }
    }
    pp::page = "login_vips";
    pp::sta = 0;
    /*pp::hall();*/
}

void pp::login_clerk( SalesData& salesdata ){
    __int64 dist{ 0 };
    std::string tmp1, tmp2;

    std::cout << "\n请输入账号: _____\b\b\b\b\b";
    std::cin >> tmp1;

    std::cout << "\n请输入密码: ______\b\b\b\b\b\b";
    std::cin >> tmp2;

    auto iter = salesdata.clerk.begin();
    while ( iter != salesdata.clerk.end() )
    {
        if ( tmp1 == ( iter->getID() ) )
        {
            auto iter_match = iter;
            dist = std::distance( salesdata.clerk.begin(), iter_match );
            std::cout << "Here is the Clerks in: NO. \t" << dist + 1 << std::endl;
            std::cout << "ID is :\n";
            std::cout
                << std::setw( 20 )
                << std::right
                << ( iter_match->getID() )
                << '\t';
            if ( tmp2 == ( iter_match->getPWD() ) )
            {
                std::cout << "Welcome!\n\n";
                pp::manager( TRUE );
            }
            else
            {
                std::cout << "Error: There is a wrong accout PWD  " << tmp2 << " here.\n\n";
                std::cout << "Again? Y/N : _\b";
                std::cin >> tmp2;
                if ( tmp2 == "Y" || tmp2 == "y" )
                {
                    login_clerk( salesdata );
                    pp::page = "login_clerk";
                    pp::sta = 0;
                }
                else
                    pp::hall();
            }
        }
        else;
        ++iter;
        if ( ( iter == salesdata.clerk.end() ) && ( dist == -1 ) )
        {
            std::cout << "Error: There is a wrong accout ID:  " << tmp1 << " here.\n\n";
            pp::hall();
        }
    }
    pp::page = "login_clerk";
    pp::sta = 0;
}


void pp::printCustomer( const Customer& cus ){
    std::cout << std::left << std::setw( 20 ) << "Customer's ID: " << std::right << std::setw( 20 ) << cus.getID() << std::endl \
        << std::left << std::setw( 20 ) << "Customer's Name: " << std::right << std::setw( 20 ) << cus.getName() << std::endl;
}

void pp::printBook( const Book& book ){
    pp::printTitle(book);
    std::cout << std::left << std::setw( 20 ) << "price: " << std::right << std::setw( 20 ) << std::setprecision( 4 ) << book.getPrice() << std::endl;
    std::cout << std::left << std::setw( 20 ) << "total: " << std::right << std::setw( 20 ) << std::setprecision( 4 ) << book.getTotal() << std::endl;
}

void pp::printTitle( const Title& title ){
    std::cout << std::left << std::setw( 20 ) << "Book's Name: " << std::right << std::setw( 20 ) << title.getBookName() << std::endl \
        << std::left << std::setw( 20 ) << "Book's Author: " << std::right << std::setw( 20 ) << title.getAuthor() << std::endl \
        << std::left << std::setw( 20 ) << "Book's ISBN: " << std::right << std::setw( 20 ) << title.getISBN() << std::endl;
}

void pp::printAllBook( BookList& bookdata ){

    for ( auto iter_book = bookdata.book.begin(); iter_book != bookdata.book.end(); ++iter_book)
    {
        std::cout 
            << std::right << std::setw( 20 ) 
            << ( iter_book->getBookName() )
            << ' ';
        std::cout 
            << std::right << std::setw( 20 )
            << ( iter_book->getISBN() )
            << ' ';
        std::cout 
            << std::right << std::setw( 20 )
            << ( iter_book->getAuthor() )
            << ' ';
        std::cout 
            << std::right << std::setw( 20 )
            << ( iter_book->getPrice() )
            << ' ';
        std::cout 
            << std::right << std::setw( 20 )
            << ( iter_book->getNum() )
            << '\n';
    }
}


void pp::get_sta( std::istream& in){
    in >> pp::sta;
}

void pp::tips(){
    std::cout << "\n提示：请输入编号进行操作: _\b";
}

void pp::error(){
    std::cout << "\n错误输入：请输入正确的编号进行操作: _\b";
    std::cin.clear();                   //  清掉错误标志位，不然死在cin
    std::cin.ignore( INT_MAX, '\n' );
}

#endif
#endif


