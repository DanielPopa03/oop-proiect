#ifndef _PIZZA_H
#define _PIZZA_H
#include <iostream>
#include <string>
#include "Product.h"
class Pizza:virtual public Product{
    protected:
        std::string crustType;
        std::string toppings;
    public:
        Pizza(const std::string& name_, const std::string  & size_, const std::string &ingredients_, double pret_,const std::string& crustType_, const std::string& toppings_);
       // ~Pizza()=default;
       ~Pizza() = default;
        Pizza(const Pizza& obj);
        virtual Pizza* clone(){return (new Pizza(*this));}
        void print(std::ostream& os, Product& dt);
};
#endif