#include "../headere/kebab.h"


Kebab::Kebab(const std::string& name_, const std::string  & size_, const std::string &ingredients_, double price_,const std::string& typeOfMeat_):
Product(name_, size_, ingredients_,price_),typeOfMeat{typeOfMeat_}{}; 


Kebab::Kebab(const Kebab& obj):Product(obj){
    
    std::cout<<"constr copy Kebab"<<std::endl;
    this->typeOfMeat = obj.typeOfMeat;
}

void Kebab::print(std::ostream& os, Product& dt){
   try{
    Kebab obj = dynamic_cast<Kebab&>(dt);
    os << obj.name << '/' << obj.size << '/';
    for(auto&i : obj.ingredients){
        os<< i << "/";
    }
    os << obj.price <<"/"<<obj.typeOfMeat;
    } catch(const std::bad_cast& e){
        std::cerr << "Error in dynamic_cast: " << e.what() << std::endl;
        throw;
    }
}