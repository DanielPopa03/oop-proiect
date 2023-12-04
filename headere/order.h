#ifndef _ORDER_H
#define _ORDER_H
#include "basket.h"
#include "client.h"
class Order{
private:

    Basket Basket_;
    Client number;
    std::string methodOfDelivery;
    std::string price;

public:
    Order()=default;
};
#endif