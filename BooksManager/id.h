#ifndef  ID_H
#define  ID_H

#include <iostream>
#include <string>

class ID{
public:
    ID() = default;//{ std::cout << "ID Default Ctor.\n"; };
    ID( const std::string &userid, const std::string &userpwd );
    ID( const ID& );
    ~ID() = default;

    ID& ID::operator=( ID& acount );

    void setAccount( std::string userid , std::string userpwd ){
        this->userid = userid;
        this->userpwd = userpwd;
    }
    inline std::string getID() const {
        return this->userid;
    }
    inline std::string getPWD() const {
        return this->userpwd;
    }
private:
    std::string userid;
    std::string userpwd;
};

ID::ID( const ID& acount ) :userid( acount.userid ), userpwd( acount.userpwd ){  }
ID::ID( const std::string& userid, const std::string& userpwd ) : userid( userid ), userpwd( userpwd ){  }

ID& ID::operator=( ID& acount ){

    userid = acount.userid;
    userpwd = acount.userpwd;

    return *this;
}



#endif