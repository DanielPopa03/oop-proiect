#ifndef _BASKET_H
#define _BASKET_H
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include "Product.h"
#include "interfata.h"

class Basket{
private:
    std::vector <Product *> order;
    std::vector <Buton> displayProduct;
    std::vector <buton_Basket> deleteProduct;
    
public:
    
    Basket() = default;
    //Basket(const Basket& obj);
    ~Basket();
    void adInBasket(int id_pizza, int marime, int numar, const std::string& imagePath, const sf::Font& font, const sf::Vector2f& position);
    void deleteFromProdus( int index );
    void draw(sf::RenderWindow& window);
    void deletePr(sf::Vector2f mousePos);
    friend std::ostream& operator<<(std::ostream& out, const Basket& obj);
};

#endif