#ifndef _BASKET_H
#define _BASKET_H
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <memory>
#include "Pizza.pch"
#include "Product.h"
#include "interface.h"
#include "pizza.h"
#include "kebab.h"
#include "pizzakebab.h"

class Basket{
private:
    unsigned int numberOfProducts;
    double grandTotal ;
    std::vector < std::shared_ptr<Product> > order;
    std::vector <Buton> displayProduct;
    std::vector <buton_Basket> deleteProduct;
    friend class Order;
    
public:
    
    Basket(){numberOfProducts = 0; grandTotal = 0;}
    //Basket(const Basket& obj);
    ~Basket();
    Basket(const Basket& obj);
    double getGrandTotal(){return grandTotal;}
    void adInBasket(int id_pizza, int marime, int numar, const std::string& imagePath, const sf::Font& font, const sf::Vector2f& position);
    void deleteFromProdus( int index );
    void draw(sf::RenderWindow& window);
    void deletePr(sf::Vector2f mousePos);
    friend std::ostream& operator<<(std::ostream& out, const Basket& obj);
};

#endif
