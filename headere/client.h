#ifndef _CLIENT_H
#define _CLIENT_H
#include <iostream>
#include <string>
#include <vector>

class Client {
private:
    std::string nume;
    std::string adresa;
    std::string nrTelefon;
public:
    Client()=default;
    Client(const std::string& nume_,const std::string& adresa_);  
    friend std::ostream& operator<<(std::ostream& os, const Client& dt);
    const std::string& getNumar() const { return this->nrTelefon; }
};


#endif