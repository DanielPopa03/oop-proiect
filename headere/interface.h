#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
//#include "basket.h"
//#include "Product.h"


class buton_Basket{
    
    sf::Texture imagine;
    sf::Sprite textura;
    public:
        buton_Basket(const std::string& caleSpreImagine, const sf::Vector2f& position);
        void draw(sf::RenderWindow& window);
        void move(sf::Vector2f m){ textura.move(m);}
        bool contains(const sf::Vector2f& point) {return textura.getGlobalBounds().contains(point);}
};

class Buton {
    
        sf::RectangleShape rect;
        sf::Text text;
        
    public:
        Buton(const sf::Font& font, const std::string& label, const sf::Vector2f& position);
        void move(sf::Vector2f m){ text.move(m);rect.move(m);}
        void draw(sf::RenderWindow& window);
        bool contains(const sf::Vector2f& point) {return rect.getGlobalBounds().contains(point);}
    };

class Submenu {
   
        sf::RectangleShape rect;
        std::vector<Buton> buttons;
        bool inputNumber;
        sf::RectangleShape rect2;
        sf::Text text;
        sf::Text label;
    public:
        Submenu(const sf::Font& font, const sf::Vector2f& position);

        void draw(sf::RenderWindow& window);
        void setInput(bool state){inputNumber = state;}
        void setText(std::string text_){text.setString(text_);}
        int checkButtonClicked(const sf::Vector2f& point) ;
        void showInputState(){std::cout<<inputNumber<<std::endl;}
    };

class Client_Input{
    protected:
    int mode;
    sf::RectangleShape rect;
    sf::Text text;
    sf::Text label;
    sf::Texture imagine;
    sf::Sprite textura;
    public:
        Client_Input(const std::string& caleSpreImagine, const sf::Font& font, const sf::Vector2f& position);
        void draw(sf::RenderWindow& window);
        void setText(std::string text_){if(mode < 3)text.setString(text_);}
        bool contains(const sf::Vector2f& point); 
};

#endif
