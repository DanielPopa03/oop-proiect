#include "../headere/Product.h"





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





