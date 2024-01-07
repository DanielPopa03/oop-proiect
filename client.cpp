#include "../headere/client.h"
//s
std::ostream& operator<<(std::ostream& os, const Client& dt)
    {
    os << dt.nume << '/' << dt.adresa << '/' << dt.nrTelefon;
    return os;
    }

Client::Client(const std::string& nume_,const std::string& adresa_) : nume{nume_},adresa{adresa_} {} 
