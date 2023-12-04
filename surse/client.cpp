#include "../headere/client.h"

std::ostream& operator<<(std::ostream& os, const Client& dt)
    {
    os << dt.name << '/' << dt.address << '/' << dt.phoneNumber;
    return os;
    }
