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
    void reserv( Customer& cus );
    void login_vips( Customer& cus, SalesData& salesdata );
    void login_clerk( Clerk& cle, SalesData& salesdata );
    
    void manager_no_root( Customer& cus );
    void manager_root( Clerk& cle );

    void find_bookName( Customer& cus, BookList& bookdata );
    void find_isbn( Customer& cus, BookList& bookdata );
    void add_book( BookList& bookdata );
    void delete_book( BookList& bookdata );
    void modify_book( BookList& bookdata );
    void modify_hall();
    std::string modify_bookName();
    std::string modify_ISBN();
    std::string modify_author();
    double modify_price();
    int modify_num();


    void tips();
    void error();
    void _exit( BookList& bookdata, SalesData& salesdata ){ saveAllData( bookdata, salesdata ); exit( 0 ); }
    void what_is_sta( BookList& bookdata, SalesData& salesdata );
    void get_sta( std::istream& in );
    void set_sta( std::string p, int sta ){ pp::page = p; pp::sta = sta; }

    void printLoan( Customer& cus );
    void printALoan( Loan& loan );
    void printAllLoan( SalesData& salesdata );

    void printCustomer(const Customer& cus);
    void printBook( const Book& book );
    void printTitle( const Title& title );
    void printAllBook( BookList& bookdata );


};


void pp::what_is_sta( BookList& bookdata, SalesData& salesdata ){
    Customer cus;
    Clerk cle;
    while ( 1 )
    {
        pp::get_sta( std::cin );
        std::cout << "\n\n";
        // 前两个交互页
        if ( pp::page == "hall" )
        {
            switch ( pp::sta )
            {
                case 1:pp::login_vips( cus,salesdata ); break;
                case 2:pp::login_clerk( cle,salesdata ); break;
                case 3:pp::_exit( bookdata, salesdata ); break;
                default:pp::error(); break;
            }
        }
        else if ( pp::page == "manager_root" )
        {
            switch ( pp::sta )
            {
                case 1:pp::add_book( bookdata ); pp::manager_root( cle ); break;
                case 2:pp::delete_book( bookdata ); pp::manager_root( cle ); break;
                case 3:pp::modify_book( bookdata );  pp::manager_root( cle ); break;
                case 4:pp::printAllLoan( salesdata ); pp::manager_root( cle ); break;
                case 5:pp::printAllBook( bookdata ); pp::manager_root( cle ); break;
                case 6:pp::hall(); break;
                case 7:pp::_exit( bookdata, salesdata ); break;
                default:pp::error(); break;
            }
        }
        else if ( pp::page == "manager_no_root" ) {
            switch ( pp::sta )
            {
                case 1:pp::borrow(); break;
                case 2:pp::reserv(cus); break;
                case 3:pp::printLoan( cus ); pp::manager_no_root( cus ); break;
                case 4:pp::printAllBook( bookdata ); 
                       pp::manager_no_root( cus ); 
                       break;
                case 5:pp::hall(); break;
                case 6:pp::_exit( bookdata, salesdata ); break;
                default:pp::error(); break;
            }
        }
        // 现在开始是功能页
        else if ( pp::page == "borrow" )
        {
            switch ( pp::sta )
            {
                case 1:pp::find_bookName( cus, bookdata ); break;
                case 2:pp::find_isbn( cus, bookdata ); break;
                case 3:pp::printLoan( cus ); pp::manager_no_root(cus); break;
                case 4:pp::printAllBook( bookdata ); break;
                case 5:pp::_exit( bookdata, salesdata ); break;
                default:pp::error(); break;
            }
        }
        else {}
    }
}


void pp::add_book( BookList& bookdata ){

    std::string name;
    std::string isbn;
    std::string author;
    double price;
    int num;

    std::cout << "Bookname:\t";
    std::cin >> name;
    std::cout << "ISBN:\t";
    std::cin >> isbn;
    std::cout << "Author:\t";
    std::cin >> author;
    std::cout << "Price:\t";
    std::cin >> price;
    std::cout << "How many books R them:\t";
    std::cin >> num;

    bookdata.book.push_back( Book( name, author, isbn, price, num ) );
    std::cout << "已经添加到列表末尾\n";
    pp::printAllBook( bookdata );
}

void pp::delete_book( BookList& bookdata ){
    std::string isbn;
    std::cout << "\n输入要删除书籍的ISBN:\t";
    std::cin >> isbn;
    for ( auto iter = bookdata.book.begin(); iter != bookdata.book.end();) {
        if ( isbn == iter->getISBN() )
        {
            iter = bookdata.book.erase( iter );
        }
        else
        {
            ++iter;
        }
    }
    pp::printAllBook( bookdata );
    std::cout << "已删除\n";
}

void pp::modify_book( BookList& bookdata ){
    std::string isbn;
    std::cout << "\n输入要更改的书籍的ISBN:\t";
    std::cin >> isbn;
    for ( auto iter = bookdata.book.begin(); iter != bookdata.book.end(); ++iter)
    {
        if(isbn == iter->getISBN() ){
            pp::printBook( *iter );
            pp::modify_hall();
            int tmp;
            std::cin >> tmp;
            switch ( tmp )
            {
                case 1:
                    iter->setBookName( pp::modify_bookName() );
                    printBook( *iter );
                    break;
                case 2:                    
                    iter->setISBN( pp::modify_ISBN() );
                    printBook( *iter );
                    break;
                case 3:
                    iter->setAuthor( pp::modify_author() );
                    printBook( *iter );
                    break;
                case 4:
                    iter->setPrice( pp::modify_price() );
                    printBook( *iter );
                    break;
                case 5:
                    iter->setNum( pp::modify_num() );
                    printBook( *iter );
                    break;
                case 6: break;
                default:
                    pp::error();
                    break;
            }
        }
    }
}

void pp::printAllLoan( SalesData& salesdata ){
    std::cout << "\n所有外借记录:\n";
    for ( auto iter_vip = salesdata.vip.begin(); iter_vip != salesdata.vip.end(); ++iter_vip ) 
    {
        auto tmp_loan = iter_vip->getRecord();

        for ( auto iter_loan = tmp_loan.begin(); iter_loan != tmp_loan.end(); ++iter_loan )
        {
            printALoan( *iter_loan );
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void pp::hall(){

    std::cout << "1、读者维护入口" << std::endl;
    std::cout << "2、管理员维护入口" << std::endl;
    std::cout << "3、离开" << std::endl;
    pp::tips();
    pp::set_sta( "hall", 0 );
}
void pp::manager_no_root( Customer& cus ){

    std::cout << "1、借阅书目" << std::endl;
    std::cout << "2、归还书目" << std::endl;
    std::cout << "3、在借书目" << std::endl;
    std::cout << "4、现有书目" << std::endl;
    std::cout << "5、返回" << std::endl;
    std::cout << "6、离开" << std::endl;
    pp::tips();
    pp::set_sta( "manager_no_root", 0 );
}
void pp::manager_root( Clerk& cle ){

    std::cout << "1、添加书目" << std::endl;
    std::cout << "2、删除书目" << std::endl;
    std::cout << "3、更改书目" << std::endl;
    std::cout << "4、借出书目" << std::endl;
    std::cout << "5、现有书目" << std::endl;
    std::cout << "6、返回" << std::endl;
    std::cout << "7、离开" << std::endl;
    pp::tips();
    pp::set_sta( "manager_root", 0 );
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

void pp::modify_hall(){
    std::cout << "1、更改书名" << std::endl;
    std::cout << "2、更改ISBN" << std::endl;
    std::cout << "3、更改作者" << std::endl;
    std::cout << "4、更改价格" << std::endl;
    std::cout << "5、更改数量" << std::endl;
    std::cout << "6、返回" << std::endl;
    pp::tips();
}
std::string pp::modify_bookName(){
    std::string name;
    std::cout << "\nBookName:\t";
    std::cin >> name;
    return name;
}

std::string pp::modify_ISBN(){
    std::string isbn;
    std::cout << "\nBook's ISBN:\t";
    std::cin >> isbn;
    return isbn;
}

std::string pp::modify_author(){
    std::string author;
    std::cout << "\nBook's Author:\t";
    std::cin >> author;
    return author;
}

double pp::modify_price(){
    double price;
    std::cout << "\nBook's Price:\t";
    std::cin >> price;
    return price;
}

int pp::modify_num(){
    int num;
    std::cout << "\nBook's Num:\t";
    std::cin >> num;
    return num;
}

void pp::reserv( Customer& cus ){

    pp::printLoan( cus );
    std::cout << "\n输入所归还的书籍ISBN:\n";
    pp::tips();

    auto tmp = cus.getRecord();
    std::string isbn;

    std::cin >> isbn;
    
    for (auto iter=tmp.begin(); iter!=tmp.end(); ++iter){
        if(isbn == iter->getISBN()){
            auto iter_match = iter;
            std::cout << "书籍明细:\n";
            pp::printALoan(*iter_match);
            std::cout << "已归还\n";
            cus.deleteRecord( *iter_match );
        }
    }
    pp::manager_no_root( cus );
}

void pp::find_bookName( Customer& cus, BookList& bookdata ){

    __int64 dist{ -1 };
    std::string tmp;
    Date date( 2018, 02 );
    BookList booktmp;
    auto iter_tmp = booktmp.book.begin();
    std::string name;
    std::string isbn;
    std::string author;
    double price;
    int num;
    std::cout << "书名：" << std::endl;
    std::cin >> tmp;
    auto iter = bookdata.book.begin();
    while(iter!= bookdata.book.end() ){
        if ( iter->getBookName() == tmp )
        {
            auto iter_next = iter;
            dist = std::distance( bookdata.book.begin(), iter_next );
            std::cout << "Here is the book in: NO. \t" << dist + 1 << std::endl;
            name = iter_next->getBookName();
            isbn = iter_next->getISBN();
            author = iter_next->getAuthor();
            price = iter_next->getPrice();
            num = iter_next->getNum();
            std::cout 
                << std::setw(20) 
                << std::right
                << ( name )
                << ' ';
            std::cout 
                << std::setw( 20 )
                << std::right
                << ( isbn )
                << ' ';
            std::cout 
                << std::setw( 20 )
                << std::right
                << ( author )
                << ' ';
            std::cout 
                << std::setw( 20 )
                << std::right
                << ( price )
                << ' ';
            std::cout 
                << std::setw( 20 )
                << std::right
                << ( num )
                << '\n';
            booktmp.book.push_back( Book(name, author, isbn, price, num) );
        }
        else;
        ++iter;
    }
    if( ( iter == bookdata.book.end() ) && ( dist==-1 ) ){
        std::cout << "Error: There is not a book named, " << tmp << " here.\n\n";
        pp::manager_no_root( cus );
    }   
    else{
        for ( auto iter_tmp = booktmp.book.begin(); iter_tmp != booktmp.book.end(); ++iter_tmp )
        {
            cus.newRecord( Loan( *iter_tmp, date, cus.getName() ) );
            pp::printLoan( cus );
        }
        std::cout << "More books wanna to find? Y/N :_\b";
        std::cin >> tmp;
        if ( tmp == "Y" )
        {
            pp::find_bookName( cus, bookdata );
        }
        else
        {
            pp::manager_no_root(cus);
        }
    }
    pp::sta = 0;
}

void pp::find_isbn( Customer& cus, BookList& bookdata ){

    __int64 dist{ -1 };
    std::string tmp;
    Date date( 2018, 02 );
    BookList booktmp;
    
    std::string name;
    std::string isbn;
    std::string author;
    double price;
    int num;
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
            name = iter_match->getBookName();
            isbn = iter_match->getISBN();
            author = iter_match->getAuthor();
            price = iter_match->getPrice();
            num = iter_match->getNum();
            std::cout
                << std::setw( 20 )
                << std::right
                << ( name )
                << ' ';
            std::cout
                << std::setw( 20 )
                << std::right
                << ( isbn )
                << ' ';
            std::cout
                << std::setw( 20 )
                << std::right
                << ( author )
                << ' ';
            std::cout
                << std::setw( 20 )
                << std::right
                << ( price )
                << ' ';
            std::cout
                << std::setw( 20 )
                << std::right
                << ( num )
                << '\n';
            booktmp.book.push_back( Book(name, author, isbn, price, num) );
        }
        else;
        ++iter;
    }
    if ( ( iter == bookdata.book.end() ) && ( dist == -1 ) )
    {
        std::cout << "Error: There is not a book isbn, " << tmp << " here.\n\n";
        pp::manager_no_root(cus);
    }
    else
    {
        for ( auto iter_tmp = booktmp.book.begin(); iter_tmp != booktmp.book.end(); ++iter_tmp )
        {
            cus.newRecord( Loan( *iter_tmp, date, cus.getName() ) );
            pp::printLoan( cus );
        }
        std::cout << "More books wanna to find? Y/N :_\b";
        std::cin >> tmp;
        if ( tmp == "Y" || tmp == "y" )
        {
            pp::find_isbn( cus, bookdata );
        }
        else
        {
            pp::manager_no_root( cus );
        }
    }
    pp::sta = 0;
}

void pp::printLoan( Customer& cus ){
    std::cout << "Vip: " << cus.getName() << " 's Loan: \n\n";
    auto tmp = cus.getRecord();
    for ( auto iter = tmp.begin(); iter != tmp.end(); ++iter ) {
        std::cout << std::left << std::setw( 20 )
            << iter->getBookName() << ' ';
        std::cout << std::left << std::setw( 20 )
            << iter->getISBN() << ' ';
        std::cout << std::left << std::setw( 20 )
            << iter->getAuthor() << ' ';
        std::cout << std::left << std::setw( 20 )
            << iter->getPrice() << ' ';
        std::cout << std::left << std::setw( 20 )
            << iter->getNum() << '\n';
    }
    //pp::manager_no_root( cus );
}

void pp::login_vips( Customer& cus, SalesData& salesdata ){

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
                cus.setName( iter_match->getName() );
                cus.setAccount( tmp1, tmp2 );
                auto tmp = iter_match->getRecord();
                for ( auto iter_tmp = tmp.begin(); iter_tmp != tmp.end();++iter_tmp)
                {
                    cus.newRecord( Loan( *iter_tmp, Date(iter_tmp->getYear(),iter_tmp->getMonth()), cus.getName() ) );
                }
                pp::manager_no_root( cus );
            }
            else{
                std::cout << "Error: There is a wrong accout PWD  " << tmp2 << " here.\n\n";
                std::cout << "Again? Y/N : _\b";
                std::cin >> tmp2;
                if ( tmp2 == "Y" || tmp2 == "y" )
                {
                    if ( tmp2 == ( iter_match->getPWD() ) )
                    {
                        login_vips( cus, salesdata );
                        pp::page = "login_vips";
                        pp::sta = 0;
                    }
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
    //pp::page = "login_vips";
    pp::sta = 0;
    /*pp::hall();*/
}

void pp::login_clerk( Clerk& cle, SalesData& salesdata ){
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
                pp::manager_root( cle );
            }
            else
            {
                std::cout << "Error: There is a wrong accout PWD  " << tmp2 << " here.\n\n";
                std::cout << "Again? Y/N : _\b";
                std::cin >> tmp2;
                if ( tmp2 == "Y" || tmp2 == "y" )
                {
                    login_clerk( cle, salesdata );
                    /*pp::page = "login_clerk";*/
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
    /*pp::page = "login_clerk";*/
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
    std::cout << std::endl;
    std::cout << std::left << std::setw( 20 ) << "Book's Name: " << std::right << std::setw( 20 ) << title.getBookName() << std::endl \
        << std::left << std::setw( 20 ) << "Book's Author: " << std::right << std::setw( 20 ) << title.getAuthor() << std::endl \
        << std::left << std::setw( 20 ) << "Book's ISBN: " << std::right << std::setw( 20 ) << title.getISBN() << std::endl;
}

void pp::printALoan(Loan& loan){
    std::cout << std::left << std::setw( 20 )
        << loan.getBookName() << ' ';
    std::cout << std::left << std::setw( 20 )
        << loan.getAuthor() << ' ';
    std::cout << std::left << std::setw( 20 )
        << loan.getISBN() << ' ';
    std::cout << std::left << std::setw( 20 )
        << loan.getPrice() << ' ';
    std::cout << std::left << std::setw( 20 )
        << loan.getNum() << ' ';
}

void pp::printAllBook( BookList& bookdata ){

    for ( auto iter_book = bookdata.book.begin(); iter_book != bookdata.book.end(); ++iter_book)
    {
        std::cout 
            << std::left << std::setw( 20 )
            << ( iter_book->getBookName() )
            << ' ';
        std::cout 
            << std::left << std::setw( 20 )
            << ( iter_book->getISBN() )
            << ' ';
        std::cout 
            << std::left << std::setw( 20 )
            << ( iter_book->getAuthor() )
            << ' ';
        std::cout 
            << std::left << std::setw( 20 )
            << ( iter_book->getPrice() )
            << ' ';
        std::cout 
            << std::left << std::setw( 20 )
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


