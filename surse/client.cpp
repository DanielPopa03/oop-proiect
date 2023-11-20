#include "../headere/client.h"

std::ostream& operator<<(std::ostream& os, const Client& dt)
    {
    os << dt.name << '/' << dt.adress << '/' << dt.phoneNumber;
    return os;
    }

Client::Client(const std::string& name_,const std::string& adress_) : name{name_},adress{adress_} {} 