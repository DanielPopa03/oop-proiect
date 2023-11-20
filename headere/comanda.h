#ifndef _COMANDA_H
#define _COMANDA_H
#include "basket.h"
#include "client.h"
class Comanda{
private:

    Basket Basket_;
    Client number;
    std::string metodOfDelivery;
    std::string price;

public:
    Comanda()=default;
};
#endif