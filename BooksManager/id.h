#ifndef  ID_H
#define  ID_H

#include <iostream>
#include <string>

class ID{
public:
    ID() = default;
    ID( std::string userid , std::string userpwd ){
        this->userid = userid;
        this->userpwd = userpwd;
    };
    ~ID(){
       // std::cout << "ID: " << this->userid << "had been destroy.\n";
    };

    void setID( std::string userid , std::string userpwd ){
        this->userid = userid;
        this->userpwd = userpwd;
    }
    std::string getID(){
        return this->userid;
    }
private:
    std::string userid;
    std::string userpwd;
};



#endif