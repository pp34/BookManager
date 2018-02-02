#ifndef  CLERK_H
#define  CLERK_H

#include <iostream>
#include <algorithm>

#include "data.h"


class Clerk:public ID,public Person{
public:
    static int clerknum;

    Clerk() {  };

    Clerk( const Person& person, const ID& account );
    Clerk( const std::string& name, const std::string& id, const std::string& pwd );
    Clerk( const Clerk& clerk );
    ~Clerk(){ }
    
    void setClerkNum( int n ){ Clerk::clerknum = n; }
    int getClerkNum( ){ return Clerk::clerknum; }

private:
    
};

int Clerk::clerknum = 0;
Clerk::Clerk( const std::string& name, const std::string& id, const std::string& pwd ):
    Person( name ),ID( id, pwd )
{
    //++clerknum;
}

Clerk::Clerk( const Person& person, const ID& account ):
    Clerk(person.getName(),account.getID(),account.getPWD())
    {  }

Clerk::Clerk( const Clerk& clerk ):
    Clerk( clerk.getName(), clerk.getID(), clerk.getPWD() )
    {  }








#endif



