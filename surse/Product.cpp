#include "../headere/Product.h"

int Product::numberOfProducts = 0;
double Product::grandTotal = 0;

int Product::getNumberOfProducts(){return numberOfProducts;}
double Product::getGrandTotal(){return grandTotal;}

Product::Product(const std::string& name_, const std::string & size_, const std::string &ingredients_, double pret_) : name{name_},size{size_},
 ingredients{ingredients_}, price{pret_} {numberOfProducts += 1;grandTotal += this->price;};

/*void Product::print(std::ostream& os, Product& dt){
    os << dt.name << '/' << dt.size << '/' << dt.ingredients<< '/' << dt.price;
}*/
std::ostream& operator<<(std::ostream& os, Product& dt)
{
  dt.print(os, dt);
  return os;
}


Product::Product(const Product& obj){
    std::cout<<"constr copy"<<std::endl;
    numberOfProducts++;
    grandTotal += obj.price;
    this->name = obj.name;
    this->ingredients = obj.ingredients;
    this->size = obj.size;
    this->price = obj.price;

}

/*
Product Product::operator=(const Product& obj){
        if(this != &obj){
        this->ingredients = obj.ingredients;
        this->size = obj.size;
        this->price = obj.price;
        }
        return *this;
    }

void Product::setMarime(const std::string& size){
        this->size=size;
    }    */

Pizza::Pizza(const std::string& name_, const std::string & size_, const std::string &ingredients_, double pret_,const std::string& crustType_, 
const std::string& toppings_) : Product(name_, size_, ingredients_,pret_), crustType{crustType_}, toppings{toppings_}{};

Pizza Pizza::operator=(Pizza const& obj){
    if(this != &obj){
        this->name = obj.name;
        this->ingredients = obj.ingredients;
        this->size = obj.size;
        this->price = obj.price;
        this->crustType = obj.crustType;
        this->toppings = obj.toppings;
        }
        return *this;
}

Pizza::Pizza(const Pizza& obj){
    std::cout<<"constr copy Pizza"<<std::endl;
    std::cout<< obj.name << '/' << obj.size << '/' << obj.ingredients<< '/' << obj.price<<std::endl;
    numberOfProducts++;
    grandTotal += obj.price;
    this->name = obj.name;
    this->ingredients = obj.ingredients;
    this->size = obj.size;
    this->price = obj.price;
    this->size = obj.size;
    this->price = obj.price;
    this->toppings = obj.toppings;
    this->crustType = obj.crustType;
}

void Pizza::print(std::ostream& os, Product& dt){
    try{
    Pizza obj = dynamic_cast<Pizza&>(dt);
    os << obj.name << '/' << obj.size << '/' << obj.ingredients<< '/' << obj.price;
    os<<"/"<<obj.crustType<<"/"<<obj.toppings;
    } catch(const std::bad_cast& e){
        std::cerr << "Error in dynamic_cast: " << e.what() << std::endl;
        throw;
    }
}

Kebab::Kebab(const std::string& name_, const std::string & size_, const std::string &ingredients_, double price_,const std::string& typeOfMeat_):
Product(name_, size_, ingredients_,price_),typeOfMeat{typeOfMeat_}{}; 

Kebab Kebab::operator=(Kebab const& obj){

    if(this != &obj){
        this->name = obj.name;
        this->ingredients = obj.ingredients;
        this->size = obj.size;
        this->price = obj.price;
        this->typeOfMeat = obj.typeOfMeat;
        }
        return *this;
}

Kebab::Kebab(const Kebab& obj){
    std::cout<<"constr copy Kebab"<<std::endl;
    std::cout<< obj.name << '/' << obj.size << '/' << obj.ingredients<< '/' << obj.price<<std::endl;
    numberOfProducts++;
    grandTotal += obj.price;
    this->name = obj.name;
    this->ingredients = obj.ingredients;
    this->size = obj.size;
    this->price = obj.price;
    this->size = obj.size;
    this->price = obj.price;
    this->typeOfMeat = obj.typeOfMeat;
}

void Kebab::print(std::ostream& os, Product& dt){
   try{
    Kebab obj = dynamic_cast<Kebab&>(dt);
    os << obj.name << '/' << obj.size << '/' << obj.ingredients<< '/' << obj.price;
    os<<"/"<<obj.typeOfMeat;
    } catch(const std::bad_cast& e){
        std::cerr << "Error in dynamic_cast: " << e.what() << std::endl;
        throw;
    }
}

PizzaKebab::PizzaKebab(const std::string& name_, const std::string & size_, const std::string &ingredients_, double price_, const std::string& typeOfmeat_, const std::string& crustType_, const std::string& toppings_)
    : Product(name_, size_, ingredients_,price_), Pizza(name_, size_, ingredients_, price_, crustType_, toppings_), Kebab(name_, size_, ingredients_, price_, typeOfmeat_){}


PizzaKebab PizzaKebab::operator=(const PizzaKebab& obj){

        if(this != &obj){
        this->name = obj.name;
        this->ingredients = obj.ingredients;
        this->size = obj.size;
        this->price = obj.price;
        this->typeOfMeat = obj.typeOfMeat;
        this->crustType = obj.crustType;
        this->toppings = obj.toppings;
        }
        return *this;
}

PizzaKebab::PizzaKebab(const PizzaKebab& obj){
    std::cout<<"constr copy Pk  "<< obj.price <<std::endl;
    numberOfProducts++;
    grandTotal += obj.price;
    this->name = obj.name;
    this->ingredients = obj.ingredients;
    this->size = obj.size;
    this->price = obj.price;
    this->size = obj.size;
    this->price = obj.price;
    this->typeOfMeat = obj.typeOfMeat;
    this->toppings = obj.toppings;
    this->crustType = obj.crustType;
}


void PizzaKebab::print(std::ostream& os, Product& dt){
    try {
        PizzaKebab& obj = dynamic_cast<PizzaKebab&>(dt);
        os << obj.name << '/' << obj.size << '/' << obj.ingredients << '/' << obj.price;
        os << "/" << obj.typeOfMeat << "/" << obj.crustType << "/" << obj.toppings;
    } catch (const std::bad_cast& e) {
        std::cerr << "Error in dynamic_cast: " << e.what() << std::endl;
        throw;
    }
}
