#include "../headere/pizzakebab.h"

PizzaKebab::PizzaKebab(const std::string& name_, const std::string  & size_, const std::string &ingredients_, double price_, const std::string& typeOfmeat_, const std::string& crustType_, const std::string& toppings_)
    : Product(name_, size_, ingredients_,price_), Pizza(name_, size_, ingredients_, price_, crustType_, toppings_),
     Kebab(name_, size_, ingredients_, price_, typeOfmeat_){}



PizzaKebab::PizzaKebab(const PizzaKebab& obj):Product(obj),Pizza(obj),Kebab(obj){
    
    std::cout<<"constr copy Pk  "<<std::endl;
}


void PizzaKebab::print(std::ostream& os, Product& dt){
    try {
        PizzaKebab& obj = dynamic_cast<PizzaKebab&>(dt);
        os << obj.name << '/' << obj.size << '/';
                for(auto&i : obj.ingredients){
                    os<< i << "/";
                }
        os << obj.typeOfMeat << "/" << obj.crustType << "/" << obj.toppings;
    } catch (const std::bad_cast& e) {
        std::cerr << "Error in dynamic_cast: " << e.what() << std::endl;
    }
}
