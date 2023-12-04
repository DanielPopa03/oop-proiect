#ifndef _CLIENT_H
#define _CLIENT_H
#include <iostream>
#include <string>
#include <vector>
#include "interface.h"

class Client {
private:

    bool interfaceMode;
    std::string name;
    std::string address;
    std::string phoneNumber;
    
public:
    Client(){interfaceMode = 0; };
    void setInterfaceMode(int mode){if(0 <= mode && mode <= 3)this->interfaceMode = mode;}
    void setName(const std::string& name_){ this->name = name_;}
    void setAdress(const std::string& address_){ this->address = address_;}
    void setPhoneNumber(const std::string& phoneNumber_){ this->phoneNumber = phoneNumber_;}
    friend std::ostream& operator<<(std::ostream& os, const Client& dt);
    const std::string& getNumar() const { return this->phoneNumber; }
};


#endif