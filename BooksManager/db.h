#ifndef  DB_H
#define  DB_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class DB{
public:
    DB() = default;
    DB( const std::string& filename ):filename( filename ){}
    DB( const DB& db ):filename( db.filename ){}
    DB( DB&& ) noexcept;

    void read_bookName();
private:
    std::string filename;
};

DB::DB( DB&& db ) noexcept :filename( std::move( db.filename ) )  {
    db.filename = nullptr;
}

void DB::read_bookName(){
    std::string stmp;
    double ptmp;
    int ttmp;
    std::vector<std::string> name = { "Book_Name" };
    std::vector<std::string> isbn = { "Book_ISBN" };
    wchar_t author[50];
    //std::wstring author ;
    //std::vector<std::wstring> author = { "Author" };
    std::vector<double> price = { 00.00 };
    std::vector<int> total = { 0 };
    std::ifstream in;// ( filename );
    in.open( this->filename, std::ios::binary | std::ios::in );
    if (in.is_open())
    {
        while ( !in.eof() )
        {
            std::cout << stmp << std::endl;
            in >> stmp;
            name.push_back( stmp );

            in >> stmp;
            isbn.push_back( stmp );

            //in.get( author,50,'\t');
            //author.push_back( stmp );
            std::cout << author << std::endl;

            in >> ptmp;
            price.push_back( ptmp );

            in >> ttmp;
            total.push_back( ttmp );
        }

        getline( in, stmp );
    }
    else{
        std::cout << "booklist文件打开失败" << std::endl;
    }
}

#endif



