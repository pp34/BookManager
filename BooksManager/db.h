#ifndef  DB_H
#define  DB_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include "data.h"
#include "clerk.h"

const std::string __BOOKLIST_FILENAME__ = { ".book" };
const std::string __SALESLIST_FILENAME__ = { ".salesdata" };

std::string wchartostring( const char *cstr );
void saveAllData( BookList& bl, SalesData& sd );

class DB{
public:
    friend class clerk;
    friend void saveAllData( BookList& bl, SalesData& sd );
    DB() = default;
    DB( const std::string& filename ):filename( filename ){}
    DB( const DB& db ):filename( db.filename ){}
    DB( DB&& ) noexcept;


    BookList read_bookfile( BookList& bookdata );
    BookList save_bookfile( const BookList& bookdata );
    SalesData read_salesfile( SalesData& salesdata);
    SalesData save_salesfile( const SalesData& salesdata );

private:
    std::string filename = nullptr;

};

DB book_db( __BOOKLIST_FILENAME__ );
DB sales_db( __SALESLIST_FILENAME__ );

DB::DB( DB&& db ) noexcept :filename( std::move( db.filename ) )  {
    db.filename = nullptr;
}


BookList DB::save_bookfile( const BookList& bookdata ){

    std::ofstream savefile;
    savefile.open(this->filename, std::ios::out);
    
    if(savefile.is_open()){
        for ( auto iter = bookdata.book.begin(); iter != bookdata.book.end(); ++iter )
        {
            savefile << ( iter->getBookName() );
            savefile << ' ';
            savefile << ( iter->getISBN() );
            savefile << ' ';
            savefile << ( iter->getAuthor() );
            savefile << ' ';
            savefile << ( iter->getPrice() );
            savefile << ' ';
            savefile << ( iter->getNum() );
            savefile << '\n';
        }
    }
    else{
        std::cout << "Books Files do not save!\n\n";
    }
    savefile.clear();
    savefile.close();
    return bookdata;
}

BookList DB::read_bookfile( BookList& bookdata){

    char authortmp[ 50 ];
    std::string name;
    std::string author;
    std::string isbn;
    double price;
    int num;

    std::ifstream in;

    in.open( this->filename,  std::ios::binary | std::ios::in );

    if (in.is_open())
    {
        if(in.peek()==EOF){
            std::cout << "Empty File.\n" << std::endl;
        }
        //  用了5句，来代替一句 !in.eof()
        //  用指针位置来获取是否是最后一个字符，自行结束
        in.seekg( 0, std::ios::end );
        auto file_end = in.tellg();
        in.seekg( 0, std::ios::beg );
        auto file_start = in.tellg();
        while( file_end.seekpos() != file_start.seekpos() )
        {
            in >> name;
            in >> isbn;

            in.get();                           //取走开头的一个空格
            in.get( authortmp, 50, ' ' );       //这一块为了兼容中文字符读取，局限windows
            author = wchartostring( authortmp );

            in >> price;
            in >> num;
    
            bookdata.book.push_back( Book( name, author, isbn, price, num ) );

            in.get();   // for CR
            in.get();   // for LF
            file_start = in.tellg();
        }
        auto it_total = bookdata.book.begin();
        for (; it_total !=bookdata.book.end();++it_total){
            bookdata.total += it_total->getNum();
        }
        in.clear();
        in.close();
    }
    else{
        std::cout << "booklist fail to open!" << std::endl;
    }
    return bookdata;
}

SalesData DB::read_salesfile( SalesData& salesdata ){

    std::ifstream in;

    std::string name;
    std::string id;
    std::string pwd;
    std::string bookname;
    std::string isbn;
    std::string author;
    double price;
    int num;
    char root;
    char tmp;
    char ctmp[ 50 ];
    unsigned int year;
    unsigned int month;
    auto iter_vip = salesdata.vip.begin();
    in.open( this->filename, std::ios::binary | std::ios::in );
    if ( in.is_open() )
    {
        if ( in.peek() == EOF )
        {
            std::cout << "Empty File.\n" << std::endl;
        }
        //  用了5句，来代替一句 !in.eof()
        //  用指针位置来获取是否是最后一个字符，自行结束
        in.seekg( 0, std::ios::end );
        auto file_end = in.tellg();
        in.seekg( 0, std::ios::beg );
        auto file_start = in.tellg();
        while(file_end.seekpos()!=(file_start.seekpos()))
        {
            tmp = in.get();
            if ( tmp == '`' ){
                // customer
                in >> name;
                in >> id;
                in >> pwd;
                //root
                in >> root;
                if ( root == 'c' ){
                    salesdata.vip.push_back(Customer(name, id, pwd));
					iter_vip = salesdata.vip.end() - 1;
                }
                else if ( root == 'm' ){

                    salesdata.clerk.push_back( Clerk( name, id, pwd ) );
                }
                else;
            }
            else if(tmp == '='){
                //book
                in >> bookname;
                in >> isbn;
                in.get();
                in.get( ctmp, 50, ' ' );
                author = wchartostring( ctmp );
                in >> price;
                in >> num;
                //  date
                in >> year;
                in >> month;

                iter_vip->newRecord( Book( bookname, author, isbn, price, num ), Date( year, month ) );
            }
            else;
            //  'CRLF' mode
            tmp = in.get();
            tmp = in.get();
            file_start = in.tellg();
        }
        in.clear();
        in.close();
    }
    else
    {
        std::cout << "sales list fail to open!" << std::endl;
    }
    return salesdata;
}
SalesData DB::save_salesfile( const SalesData& salesdata ){ 

    std::ofstream savefile;
    savefile.open( this->filename, std::ios::out );

    if ( savefile.is_open() )
    {
        for ( auto iter_sales = salesdata.vip.begin(); iter_sales != salesdata.vip.end(); ++iter_sales )
        {
            // if ( iter_sales->getName() != "路人甲" )
            // {
            savefile << '`';
            savefile << ( iter_sales->getName() );
            savefile << ' ';
            savefile << ( iter_sales->getID() );
            savefile << ' ';
            savefile << ( iter_sales->getPWD() );
            savefile << ' ';
            savefile << 'c';
            savefile << std::endl;  // CRLF
            //}
            auto tmp = iter_sales->getRecord();
            for ( auto iter_loan = tmp.begin();
                       iter_loan != tmp.end(); 
                       ++iter_loan)
            {
                savefile << '=';
                savefile << iter_loan->getBookName();
                savefile << ' ';
                savefile << iter_loan->getISBN();
                savefile << ' ';
                savefile << iter_loan->getAuthor();
                savefile << ' ';
                savefile << iter_loan->getPrice();
                savefile << ' ';
                savefile << iter_loan->getNum();
                savefile << ' ';
                savefile << iter_loan->getYear();
                savefile << ' ';
                savefile << iter_loan->getMonth();
                savefile << std::endl;
            }
        }
        for(auto iter_clerk = salesdata.clerk.begin(); 
                 iter_clerk != salesdata.clerk.end(); 
                 ++iter_clerk ){

            savefile << '`';
            savefile << ( iter_clerk->getName() );
            savefile << ' ';
            savefile << ( iter_clerk->getID() );
            savefile << ' ';
            savefile << ( iter_clerk->getPWD() );
            savefile << ' ';
            savefile << 'm';
            savefile << std::endl;
        }
    }
    else
    {
        std::cout << "salesdata files do not save!\n\n";
    }
    savefile.clear();
    savefile.close();
    return salesdata; 
}

std::string wchartostring(const char *cstr ){

    LPSTR lstr;
    wchar_t *wstr;
    std::string str;
    int csize = MultiByteToWideChar( CP_UTF8, 0, cstr, -1, NULL, 0 );
    wstr = new wchar_t[ csize + 1 ];
    MultiByteToWideChar( CP_UTF8, 0, cstr, -1, wstr, csize );

    csize = WideCharToMultiByte( CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL );
    lstr = new char[ csize + 1 ];
    WideCharToMultiByte( CP_ACP, 0, wstr, -1, lstr, csize, NULL, NULL );
    str = lstr;

    delete[]wstr;
    delete[]lstr;

    return str;
}


void saveAllData(  BookList& bl,  SalesData& sd ){
    
    book_db.save_bookfile( bl );
    sales_db.save_salesfile( sd );
    bl.clear();
    sd.clear();
}

#endif



