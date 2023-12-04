#include "../headere/client.h"

std::ostream& operator<<(std::ostream& os, const Client& dt)
    {
    os << dt.name << '/' << dt.address << '/' << dt.phoneNumber;
    return os;
    }

Client::Client(const std::string& name_,const std::string& address_) : name{name_},address{address_} {} 