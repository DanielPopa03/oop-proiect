#include "../headere/Product.h"


Product::Product(const std::string& name_, const std::string& size_, const std::vector <std::string> &ingredients_, double pret_) : price{pret_} , name{name_},size(size_),
 ingredients{ingredients_} {};


std::ostream& operator<<(std::ostream& os, Product& dt)
{
  dt.print(os, dt);
  return os;
}


Product::Product(const Product& obj){
    this->name = obj.name;
    this->ingredients = obj.ingredients;
    this->size = obj.size;
    this->price = obj.price;

}





