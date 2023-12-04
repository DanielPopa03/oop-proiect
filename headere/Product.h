#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <iostream>
#include <string>
#include <vector>

class Product{
protected:

    
    double price;
    std::string name;
    std::string size;
    std::vector < std::string > ingredients;
    
public:
    Product() = default;
    virtual ~Product(){};
    Product(const std::string& name_,const std::string  & size_, const std::string &ingredients_, double price_);
    Product(const Product& );
    double getPrice(){return this->price;}
    //virtual Product* clone();
    virtual void print(std::ostream& os, Product& dt) = 0;
    friend std::ostream& operator<<(std::ostream& os,  Product& dt);
    //void setMarime(const std::string& size);
};





#endif