#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <iostream>
#include <string>

class Product{
protected:
    std::string name;
    std::string size;
    std::string ingredients;
    double price;
    static int numberOfProducts;
    static double grandTotal;
public:
    Product() = default;
    virtual ~Product(){numberOfProducts--;grandTotal -= this->price;};
    Product(const std::string& name_,const std::string & size_, const std::string &ingredients_, double price_);
    Product(const Product& );
    double getPret(){return this->price;}
    static int getNumberOfProducts();
    static double getGrandTotal();
    //virtual Product* clone();
    virtual void print(std::ostream& os, Product& dt)=0;
    friend std::ostream& operator<<(std::ostream& os,  Product& dt);
    //void setMarime(const std::string& size);
};

class Pizza:virtual public Product{
    protected:
        std::string crustType;
        std::string toppings;
    public:
        Pizza() = default;
        Pizza(const std::string& name_, const std::string & size_, const std::string &ingredients_, double pret_,const std::string& crustType_, const std::string& toppings_);
       // ~Pizza()=default;
       ~Pizza() = default;
        Pizza(const Pizza& obj);
        virtual Pizza* clone(){return (new Pizza(*this));}
        Pizza operator=(Pizza const& obj);
        void print(std::ostream& os, Product& dt);
};

class Kebab:virtual public Product{
    protected:
        std::string typeOfMeat;
    public:
        Kebab() = default;
        Kebab(const Kebab& obj);
        Kebab(const std::string& name_, const std::string & size_, const std::string &ingredients_, double price_,const std::string& typeOfMeat_);  
        Kebab operator=(const Kebab& obj);
        virtual Kebab* clone(){return (new Kebab(*this));}
        void print(std::ostream& os, Product& dt); 
};

class PizzaKebab:public Pizza, public Kebab{
    public:
        PizzaKebab(const PizzaKebab& obj);
        PizzaKebab operator=(const PizzaKebab&);
        PizzaKebab(const std::string& name_, const std::string & size_, const std::string &ingredients_, double price_,const std::string& typeOfMeat_,const std::string& crustType_, const std::string& toppings_);
        virtual PizzaKebab* clone(){return (new PizzaKebab(*this));}
        void print(std::ostream& os, Product& dt); 
};
#endif