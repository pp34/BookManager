#ifndef  ID_H
#define  ID_H

#include <iostream>
#include <string>

class ID{
public:
    //ID() = default;

    ID(const std::string &userid , const std::string &userpwd ):userid(userid),userpwd(userpwd){}
    ~ID(){
       // std::cout << "ID: " << this->userid << "had been destroy.\n";
    }

    void setID( std::string userid , std::string userpwd ){
        this->userid = userid;
        this->userpwd = userpwd;
    }
    inline std::string getID() const {
        return this->userid;
    }
private:
    std::string userid;
    std::string userpwd;
};



#endif