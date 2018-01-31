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
const std::string __CUSTOMERDATA_FILENAME__ = { ".vip" };
const std::string __CLERKDATA_FILENAME__ = { ".clerk" };
const std::string __LOANRECORD_FILENAME__ = { ".loan" };

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
    SalesData read_customerfile( SalesData& customerdata );
    SalesData save_customerfile( const SalesData& customerdata );
    SalesData read_loanfile( SalesData& loandata );
    SalesData save_loanfile( const SalesData& loandata );
    SalesData read_clerkfile( SalesData& clerkdata );
    SalesData save_clerkfile( const SalesData& clerkdata );
private:
    std::string filename = nullptr;

};

DB book_db( __BOOKLIST_FILENAME__ );
DB vip_db( __CUSTOMERDATA_FILENAME__ );
DB clerk_db( __CLERKDATA_FILENAME__ );
DB loan_db( __LOANRECORD_FILENAME__ );

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
        std::cout << "Books' Messages do not Match!\n\n";
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
        auto filestart = in.tellg();
        while( file_end.seekpos() != (filestart.seekpos()+1) )
        {
            in >> name;
            in >> isbn;

            in.get();                           //取走开头的一个空格
            in.get( authortmp, 50, ' ' );       //这一块为了兼容中文字符读取，局限windows
            author = wchartostring( authortmp );

            in >> price;
            in >> num;
    
            bookdata.book.push_back( Book( name, author, isbn, price, num ) );
            
            filestart = in.tellg();
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


SalesData DB::read_customerfile( SalesData& customerdata ){

    std::ifstream in;
    std::string name;
    std::string id;
    std::string pwd;

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
        auto filestart = in.tellg();
        while ( file_end.seekpos() != ( filestart.seekpos() + 1 ) )
        {
            in >> name;
            in >> id;
            in >> pwd;

            customerdata.vip.push_back( Customer( name , id , pwd ) );

            filestart = in.tellg();
        }
        in.clear();
        in.close();
    }
    else
    {
        std::cout << "viplist fail to open!" << std::endl;
    }
    return customerdata;
}

SalesData DB::save_customerfile( const SalesData& customerdata ){

    std::ofstream savefile;
    savefile.open( this->filename, std::ios::out );

    if ( savefile.is_open() )
    {
        for ( auto iter = customerdata.vip.begin(); iter != customerdata.vip.end(); ++iter )
        {
            savefile << ( iter->getName() );
            savefile << ' ';
            savefile << ( iter->getID() );
            savefile << ' ';
            savefile << ( iter->getPWD() );
            savefile << '\n';
        }
    }
    else
    {
        std::cout << "Vips' Messages do not Match!\n\n";
    }
    savefile.clear();
    savefile.close();
    return customerdata;
}

SalesData DB::read_loanfile( SalesData& loandata){

    char ctmp[ 50 ];
    std::string id;
    std::string bookname, author, isbn;
    double price;
    int num;
    unsigned int year;
    unsigned int month;
    std::ifstream in;
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
        auto filestart = in.tellg();
        while ( file_end.seekpos() != ( filestart.seekpos() + 1 ) )
        {
            in >> id;
            //  book
            in >> bookname;
            in >> isbn;
            in.get();
            in.get( ctmp,50,' ' );
            author=wchartostring(ctmp);
            in >> price;
            in >> num;
            //  date
            in >> year;
            in >> month;
            loandata.loan.push_back( Loan(Book( bookname, author, isbn, price,num ),Date( year , month ), id ) );
            
            filestart = in.tellg();
        }
        in.clear();
        in.close();
    }
    else
    {
        std::cout << "loan record fail to open!" << std::endl;
    }
    return loandata;
}

SalesData DB::save_loanfile( const SalesData& loandata ){

    std::ofstream savefile;
    savefile.open( this->filename, std::ios::binary|std::ios::out );
    
    if ( savefile.is_open() )
    {
        for ( auto iter_loan = loandata.loan.begin(); iter_loan != loandata.loan.end(); ++iter_loan )
        {
            savefile << ( iter_loan->getWho() );
            savefile << ' ';
            savefile << ( iter_loan->getBookName() );
            savefile << ' ';
            savefile << ( iter_loan->getISBN() );
            savefile << ' ';
            savefile << ( iter_loan->getAuthor() );
            savefile << ' ';
            savefile << ( iter_loan->getPrice() );
            savefile << ' ';
            savefile << ( iter_loan->getNum() );
            savefile << ' ';
            savefile << ( iter_loan->getYear() );
            savefile << ' ';
            savefile << ( iter_loan->getMonth() );
            savefile << '\n';
        }
    }
    else
    {
        std::cout << "Loan's Messages do not Match!\n\n";
    }
    savefile.clear();
    savefile.close();
    return loandata;
}

SalesData DB::read_clerkfile( SalesData& clerkdata ){
    std::ifstream in;
    std::string name;
    std::string id;
    std::string pwd;
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
        auto filestart = in.tellg();
        while ( file_end.seekpos() != ( filestart.seekpos() + 1 ) )
        {
            in >> name;
            in >> id;
            in >> pwd;
            clerkdata.clerk.push_back( Clerk( name, id, pwd ) );

            filestart = in.tellg();
        }
        in.clear();
        in.close();
    }
    else
    {
        std::cout << "clerk list fail to open!" << std::endl;
    }
    return clerkdata;
}

SalesData DB::save_clerkfile( const SalesData& clerkdata ){
    std::ofstream savefile;
    savefile.open( this->filename, std::ios::out );

    if ( savefile.is_open() )
    {
        for ( auto iter_clerk = clerkdata.clerk.begin(); iter_clerk != clerkdata.clerk.end(); ++iter_clerk )
        {
            savefile << ( iter_clerk->getName() );
            savefile << ' ';
            savefile << ( iter_clerk->getID() );
            savefile << ' ';
            savefile << ( iter_clerk->getPWD() );
            savefile << '\n';
        }
    }
    else
    {
        std::cout << "Clerks' Messages do not Match!\n\n";
    }
    savefile.clear();
    savefile.close();
    return clerkdata;
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
    char tmp;
    char ctmp[ 50 ];
    unsigned int year;
    unsigned int month;

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
        auto filestart = in.tellg();
        while ( file_end.seekpos() != ( filestart.seekpos() + 1 ) )
        {
            // customer
            in >> name;
            in >> id;
            in >> pwd;
            //root
            in >> tmp;
            if(tmp == 'c'){
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
            }
            tmp = in.get();
            if ( tmp == '`' ) { in.get(); }
            //clerkdata.clerk.push_back( Clerk( name, id, pwd ) );

            filestart = in.tellg();
        }
        in.clear();
        in.close();
    }
    else
    {
        std::cout << "clerk list fail to open!" << std::endl;
    }
    return salesdata;
}
SalesData DB::save_salesfile( const SalesData& salesdata ){ return salesdata; }

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
    vip_db.save_customerfile( sd );
    clerk_db.save_clerkfile( sd );
    loan_db.save_loanfile( sd );
    bl.clear();
    sd.clear();
}

#endif



