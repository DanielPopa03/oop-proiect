#ifndef _INTERFATA_H
#define _INTERFATA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
//#include "basket.h"
#include "Product.h"


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
    public:
        Submenu(const sf::Font& font, const sf::Vector2f& position);

        void draw(sf::RenderWindow& window);

        int checkButtonClicked(const sf::Vector2f& point) ;
    };

/*class butoaneProduseBasket {
  std::vector <Buton> afisareTipProdus;
  std::vector <buton_Basket> scoateProdus;
  
  public:
   butoaneProduseBasket( const sf::Font& font, const std::string& caleSpreImagine, const sf::Vector2f& position, const Basket& obj );
   void draw( sf::RenderWindow& window);
   void stergeProdus(Basket& obj, int index );
};*/

#endif
