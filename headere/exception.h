#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <exception>
#include <chrono>
#include <thread>

class EnterException : public std::exception {
public:
    EnterException(sf::RenderWindow& window, const sf::Font& font){
        window.clear(sf::Color::White);
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(340, 60));
        rect.setPosition(sf::Vector2f(300, 300));
        rect.setFillColor(sf::Color::Red);
        sf::Text text;
        text.setFont(font);
        text.setString("YOU MUST ENTER A VALID NUMBER!! ");
        text.setPosition(sf::Vector2f(300, 300));
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Black);
        
        window.draw(rect);
        window.draw(text);
        window.display();
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
    }
    const char* what() const noexcept {
        return "\n YOU MUST ENTER A VALID NUMBER!! \n";
    }
};

class DeleteException : public std::exception {
public:
    DeleteException(sf::RenderWindow& window, const sf::Font& font){
        window.clear(sf::Color::White);
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(340, 60));
        rect.setPosition(sf::Vector2f(300, 300));
        rect.setFillColor(sf::Color::Red);
        sf::Text text;
        text.setFont(font);
        text.setString("YOU CANNOT DELETE!!  ");
        text.setPosition(sf::Vector2f(300, 300));
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Black);
        
        window.draw(rect);
        window.draw(text);
        window.display();
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
    }
    const char* what() const noexcept {
        return "\n YOU CANNOT DELETE!! \n";
    }
};


#endif
