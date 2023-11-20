#ifndef _CLIENT_H
#define _CLIENT_H
#include <iostream>
#include <string>
#include <vector>

class Client {
private:
    std::string name;
    std::string adress;
    std::string phoneNumber;
public:
    Client()=default;
    Client(const std::string& name_,const std::string& adress_);  
    friend std::ostream& operator<<(std::ostream& os, const Client& dt);
    const std::string& getNumar() const { return this->phoneNumber; }
};


#endif