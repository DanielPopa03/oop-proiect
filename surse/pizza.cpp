#include "../headere/pizza.h"


Pizza::Pizza(const std::string & marime_, const std::string &ingrediente_, double pret_) : marime{marime_}, ingrediente{ingrediente_}, pret{pret_} {};

std::ostream& operator<<(std::ostream& os, const Pizza& dt)
{
os << dt.marime << '/' << dt.ingrediente<< '/' << dt.pret;
return os;
}

Pizza::Pizza(const Pizza& obj){
    this->ingrediente = obj.ingrediente;
    this->marime = obj.marime;
    this->pret = obj.pret;

}


Pizza Pizza::operator=(const Pizza& obj){
        if(this != &obj){
        this->ingrediente = obj.ingrediente;
        this->marime = obj.marime;
        this->pret = obj.pret;
        }
        return *this;
    }

/*void Pizza::setMarime(const std::string& marime){
        this->marime=marime;
    }   */ 

