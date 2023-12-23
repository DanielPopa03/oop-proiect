#ifndef _KEBAB_H
#define _KEBAB_H
#include <iostream>
#include <string>
#include "Product.h"
class Kebab:virtual public Product{
    protected:
        std::string typeOfMeat;
    public:
        Kebab(const Kebab& obj);
        Kebab(const std::string& name_, const std::string  & size_, const std::vector<std::string>  &ingredients_, double price_,const std::string& typeOfMeat_);  
        virtual Kebab* clone(){return (new Kebab(*this));}
        void print(std::ostream& os, Product& dt) override; 
};

class Kebab_factory{
    public:
        static Kebab Beef_Kebab(std::string size);
        static Kebab Chicken_Kebab(std::string size);
};

#endif