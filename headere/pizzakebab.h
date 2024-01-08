
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
        PizzaKebab(const std::string& name_, const std::string & size_, const std::vector <std::string> &ingredients_, double price_,const std::string& typeOfMeat_,const std::string& crustType_, const std::string& toppings_);
        virtual PizzaKebab* clone() override{return (new PizzaKebab(*this));}
        void print(std::ostream& os, Product& dt) override ; 
};

class PizzaKebab_factory{
    public:
        static PizzaKebab PizzaKebabc(const std::string& size){
            double price;
            if(size.compare("Small")== 0){price = 25;} else price = 25;
            if(size.compare("Medium")== 0){price = 30;}
            if(size.compare("Large")== 0){price = 35;}
            std::vector <std::string> ingredients;
            ingredients.push_back("Special dough");
            ingredients.push_back("Tomatoes");
            ingredients.push_back("Cheese");
            ingredients.push_back("Cold cut");
            ingredients.push_back("Sausages");
            ingredients.push_back("Eggs");
            ingredients.push_back("Butter");
            return PizzaKebab("Pizza Margerita", size,ingredients,price,"chicken","soft","mozzarella, cold cuts and sausages");
        }
};
#endif
