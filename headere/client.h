#ifndef _CLIENT_H
#define _CLIENT_H
#include <iostream>
#include <string>
#include <vector>
#include "interface.h"

class Client {
private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    friend class Client_builder;
public:
    
    friend std::ostream& operator<<(std::ostream& os, const Client& dt);
    const std::string& getNumar() const { return this->phoneNumber; }
};

class Client_builder:public Client_Input {
private:
    Client C;
public:
    Client_builder(const std::string& caleSpreImagine, const sf::Font& font, const sf::Vector2f& position):Client_Input(caleSpreImagine,font,position){};
    bool ready(){if(mode >= 3) return 1; else return 0;}
    void pushText(const std::string& text);

    Client_builder& name(const std::string& name_) {
        C.name = name_;
        return *this;
    }
    Client_builder& address(const std::string& address_) {
        C.address = address_;
        return *this;
    }
    Client_builder& phoneNumber(const std::string& phoneNumber_) {
        C.phoneNumber = phoneNumber_;
        return *this;
    }
    Client build() {
        return C;
    }
    bool contains(const sf::Vector2f& point); 
};

#endif