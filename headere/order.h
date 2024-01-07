#ifndef _ORDER_H
#define _ORDER_H
#include <codecvt>
#include <fstream>
#include "basket.h"
#include "client.h"
#include "interface.h"
class Order{
private:

    Basket Basket_;
    Client cl;
    std::string methodOfDelivery;
    double price;
    int mode;
    int actualDispalyMode;
    std::vector <std::vector <sf::Text>> text;
public:
    //Order() = default;
    Order(const sf::Font& font, const sf::Vector2f& windowSize, const Basket& Basket__,const Client& cl_, 
    const std::string& methodOfDelivery_, const double price_);
    void printReceipt();
    void draw(sf::RenderWindow& window);
    void moveSlide(int delta);
    void print(){
        for (int i = 0; i < mode ; i++){
            for (unsigned int j = 0; j < text[i].size(); j++){
                std::string c = text[i][j].getString();
                std::cout<< c;
            }
            std::cout<<std::endl;
        }
    }
};
#endif
