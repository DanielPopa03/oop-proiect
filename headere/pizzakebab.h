
#ifndef _PIZZAKEBAB_H
#define _PIZZAKEBAB_H
#include <iostream>
#include <string>
#include "Product.h"
#include "pizza.h"
#include "kebab.h"

class PizzaKebab:public Pizza, public Kebab{
    public:
        PizzaKebab(const PizzaKebab& obj);
        PizzaKebab(const std::string& name_, const std::string & size_, const std::string &ingredients_, double price_,const std::string& typeOfMeat_,const std::string& crustType_, const std::string& toppings_);
        virtual PizzaKebab* clone(){return (new PizzaKebab(*this));}
        void print(std::ostream& os, Product& dt); 
};


#endif