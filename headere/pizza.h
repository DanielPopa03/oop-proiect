#ifndef _PIZZA_H
#define _PIZZA_H
#include <iostream>
#include <string>

class Pizza{
private:
    std::string marime;
    std::string ingrediente;
    double pret;

public:
    Pizza() = default;
    ~Pizza() = default;
    Pizza(const std::string & marime_, const std::string &ingrediente_, float pret_);
    
    Pizza operator=(Pizza const& obj);
    double getPret(){return this->pret;}
    friend std::ostream& operator<<(std::ostream& os, const Pizza& dt);
    void setMarime(const std::string& marime);
};
#endif