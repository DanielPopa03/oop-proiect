#ifndef _INTERFATA_H
#define _INTERFATA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

class buton_Cos{
    sf::Texture imagine;
    sf::Sprite textura;
    sf::RectangleShape rect;
    sf::Text text; 
    public:
        buton_Cos(const sf::Font& font, const std::string& caleSpreImagine,const sf::Vector2f& position);
        void draw(sf::RenderWindow& window);
        bool contains(const sf::Vector2f& point) {return textura.getGlobalBounds().contains(point);}
};

class Buton {
        sf::RectangleShape rect;
        sf::Text text;
        bool active = false;
    public:
        Buton(const sf::Font& font, const std::string& label, const sf::Vector2f& position);
        
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
#endif
