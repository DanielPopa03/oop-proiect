#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <string>
#include "headere/interfata.h"
#include "headere/pizza.h"
#include "headere/cos.h"
#include "headere/client.h"
#include "headere/comanda.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pizzeria lui Dorel");
    window.setFramerateLimit(60);

    
    sf::Font font;
    font.loadFromFile("DejaVuMathTeXGyre.ttf"); 

        

    std::vector<Buton> mainButtons;
    mainButtons.emplace_back(font, "Pizza Margerita", sf::Vector2f(100, 100));
    mainButtons.emplace_back(font, "Button 2", sf::Vector2f(100, 160));
    mainButtons.emplace_back(font, "Button 3", sf::Vector2f(100, 220));
    mainButtons.emplace_back(font, "Button 4", sf::Vector2f(100, 280));
    mainButtons.emplace_back(font, "Button 5", sf::Vector2f(100, 340));
    
    buton_Cos butonCos(font,"imagine.png",sf::Vector2f(700,0));

    std::vector<Buton> extraOptionsButtons;
    extraOptionsButtons.emplace_back(font, "Button 1", sf::Vector2f(300, 200));
    extraOptionsButtons.emplace_back(font, "Button 1", sf::Vector2f(300, 200));
    extraOptionsButtons.emplace_back(font, "Button 1", sf::Vector2f(300, 200));
    extraOptionsButtons.emplace_back(font, "Button 1", sf::Vector2f(300, 200));
    extraOptionsButtons.emplace_back(font, "Button 1", sf::Vector2f(300, 200));

    // Submenu variables
    Submenu submenu(font, sf::Vector2f(300, 200));
    int selectedMainButton = -1;
    int selectedSubmenuOption = -1;
    std::string numberInput;
    int enteredNumber;
   
    bool submenuOpen = false;
    

    
    Pizza *dummy=nullptr;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                // Check if any main button is clicked
                if (!submenuOpen) {
                    for (int i = 0; i < mainButtons.size(); ++i) {
                        if (mainButtons[i].contains(mousePos)) {
                            switch (i)
                            {
                            case 0:
                                dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
                                break;
                            case 1:
                                dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
                                break;
                            case 2:
                                dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
                                break;
                            case 3:
                                dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
                                break;
                            case 4:
                                dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
                                break;
                            }
                            selectedMainButton = i;//////!!!!!!!!!!!!
                            submenuOpen = true;
                            break;
                        }
                    }
                } else {
                    // Handle submenu button clicks
                    selectedSubmenuOption = submenu.checkButtonClicked(mousePos);//////!!!!!!!!!!!!
                    if (selectedSubmenuOption != -1) {
                        ///Ask for a number input
                        
                        enteredNumber = 0;
                        sf::Vector2f mouseP(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                        while (window.isOpen()) {
                            sf::Event numEvent;
                            while (window.pollEvent(numEvent)) {
                                
                                if (numEvent.type == sf::Event::Closed) {
                                       window.close();
                                }
                                if (numEvent.type == sf::Event::TextEntered) {
                                    if (std::isdigit(numEvent.text.unicode)) {
                                        numberInput = static_cast<char>(numEvent.text.unicode);
                                        enteredNumber = std::stoi(numberInput);
                                        std::cout<<numberInput<<" "<<enteredNumber<<std::endl;
                                        numberInput="";
                                    }
                                    submenuOpen = false;
                                    
                                }
                            }
                            if (!submenuOpen) {
                                break;
                            }
                        }
                    }
                    window.clear(sf::Color::White);
                    
                }
            }
        }

        window.clear(sf::Color::White);

        // Draw main buttons
        for (auto& button : mainButtons) {
            button.draw(window);
        }
        
        butonCos.draw(window);

        // Draw submenu if open
        if (submenuOpen) {
            submenu.draw(window);
            
        }

        window.display();
    }

    if(dummy != nullptr) delete dummy;

    return 0;
}

