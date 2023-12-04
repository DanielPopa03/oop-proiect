#include "../headere/pizza.h"
Pizza::Pizza(const std::string& name_, const std::string& size_, const std::string &ingredients_, double pret_,const std::string& crustType_, 
const std::string& toppings_) : Product(name_, size_, ingredients_,pret_), crustType{crustType_}, toppings{toppings_}{};

Pizza::Pizza(const Pizza& obj):Product(obj){

    std::cout<<"constr copy Pizza"<<std::endl;
    this->toppings = obj.toppings;
    this->crustType = obj.crustType;
}

void Pizza::print(std::ostream& os, Product& dt){
    try{
    Pizza obj = dynamic_cast<Pizza&>(dt);
    os << obj.name << '/' << obj.size << '/';
    for(auto&i : obj.ingredients){
        os<< i << "/";
    }
    os << obj.price << "/" << obj.crustType << "/" << obj.toppings;
    } catch(const std::bad_cast& e){
        std::cerr << "Error in dynamic_cast: " << e.what() << std::endl;
        
    }
}