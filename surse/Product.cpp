#include "../headere/Product.h"


Product::Product(const std::string& name_, const std::string& size_, const std::string &ingredients_, double pret_) : name{name_},size(size_),
 ingredients{ingredients_}, price{pret_} {};


std::ostream& operator<<(std::ostream& os, Product& dt)
{
  dt.print(os, dt);
  return os;
}


Product::Product(const Product& obj){
    std::cout<<"constr copy"<<std::endl;
    this->name = obj.name;
    this->ingredients = obj.ingredients;
    this->size = obj.size;
    this->price = obj.price;

}





