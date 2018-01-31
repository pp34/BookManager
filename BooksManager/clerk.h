#ifndef  CLERK_H
#define  CLERK_H

#include <iostream>
#include <algorithm>

#include "data.h"


class Clerk:public ID,public Person{
public:
    static int clerknum;

    Clerk() { ++clerknum; };

    Clerk( const Person& person, const ID& account );
    Clerk( const std::string& name, const std::string& id, const std::string& pwd );
    Clerk( const Clerk& clerk );
    ~Clerk(){ --clerknum; }

    void add_book(BookList& booklist, const Book& book){
        booklist.book.push_back( book );
    }

    void delete_book( BookList& booklist, const Book& book ){
        auto it_book = std::find( booklist.book.begin(), booklist.book.end(), book );
        if ( it_book == booklist.book.end() )
            std::cout << "This book U wanna delete not Found.\n\n";
        else {
            it_book= booklist.book.erase( it_book );
            std::cout << "Delete Complete.\n\n";
        }
    }

private:
    
};

int Clerk::clerknum = 0;
Clerk::Clerk( const std::string& name, const std::string& id, const std::string& pwd ):
    Person( name ),ID( id, pwd )
{
    ++clerknum;
}

Clerk::Clerk( const Person& person, const ID& account ):
    Clerk(person.getName(),account.getID(),account.getPWD())
    { ++clerknum; }

Clerk::Clerk( const Clerk& clerk ):
    Clerk( clerk.getName(), clerk.getID(), clerk.getPWD() )
    { ++clerknum; }








#endif



