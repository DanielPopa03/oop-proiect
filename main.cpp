#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <string>
#include "headere/interfata.h"
#include "headere/Product.h"
#include "headere/basket.h"
#include "headere/client.h"
#include "headere/comanda.h"



int main() {
    
    Basket _Basket;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Pizzeria lui Dorel");
    window.setFramerateLimit(60);

    
    sf::Font font;
    font.loadFromFile("DejaVuMathTeXGyre.ttf"); 

        

    std::vector<Buton> mainButtons;
    mainButtons.emplace_back(font, "Pizza Margerita", sf::Vector2f(100, 100));
    mainButtons.emplace_back(font, "Pizza Casei", sf::Vector2f(100, 160));
    /*mainButtons.emplace_back(font, "Pizza Capricioasa", sf::Vector2f(100, 220));
    mainButtons.emplace_back(font, "Pizza Polo Italiano", sf::Vector2f(100, 280));
    mainButtons.emplace_back(font, "Pizza Roma", sf::Vector2f(100, 340));*/
    mainButtons.emplace_back(font, "Chicken Kebab", sf::Vector2f(100, 220));
    mainButtons.emplace_back(font, "Beef Kebab", sf::Vector2f(100, 280));
    mainButtons.emplace_back(font, "Pizza Kebab", sf::Vector2f(100, 340));
    //Buton Basket
    buton_Basket butonBasket("imagine.png",sf::Vector2f(700,0));
    bool butonBasketActiv = false;

    //Inchide Basket
    buton_Basket inBasket("inchide.png", sf::Vector2f(700,0));
     
    
    // Submenu variabile
    Submenu submenu(font, sf::Vector2f(300, 200));
    int selectedMainButton = -1;
    int selectedSubmenuOption; //= -1;
    std::string numberInput;
    int enteredNumber;
   
    bool submenuOpen = false;
    
    


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            //std::cout<<Product::getGrandTotal()<<" "<<Product::getNumberOfProducts()<<std::endl;
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                if(butonBasket.contains(mousePos)){
                   
                   butonBasketActiv = true;
                   sf::Event cosEvent;

                   if (butonBasketActiv)
                   {
                      
                      //if( event.type == sf::Event::Closed){ window.close();}
                      if( inBasket.contains(mousePos)){ butonBasketActiv = false; }
                      
                   }
                   
                }
                if(butonBasketActiv){
                _Basket.deletePr(mousePos);
                //std::cout<<Product::getGrandTotal()<<" "<<Product::getNumberOfProducts()<<std::endl;
                }
                // Verifica daca vreunuk din main button e apasat
                if (!submenuOpen && !butonBasketActiv) {
                    for (unsigned i = 0; i < mainButtons.size(); ++i) {
                        if (mainButtons[i].contains(mousePos)) {
                            selectedMainButton = i;//////!!!!!!!!!!!!
                            submenuOpen = true;
                            break;
                        }
                    }
                } else {
                    // ce submenu button a fost apasat
                    selectedSubmenuOption = submenu.checkButtonClicked(mousePos);//////!!!!!!!!!!!!
                    if (selectedSubmenuOption != -1) {
                        
                        //enteredNumber = 0;
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
                                        _Basket.adInBasket(selectedMainButton, selectedSubmenuOption, enteredNumber,"inchide.png" ,font, sf::Vector2f(200,100));
                                        std::cout<<Product::getGrandTotal()<<" "<<Product::getNumberOfProducts()<<std::endl;
                                        std::cout<<_Basket;
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

        window.clear(sf::Color::Red);
    if(butonBasketActiv == false){
        // Draw main buttons
        for (auto& button : mainButtons) {
            button.draw(window);
        }
        
        butonBasket.draw(window);

        // Draw submenu if open
        if (submenuOpen) {
            submenu.draw(window);
            
        }
    }
    else{
        inBasket.draw(window);
        _Basket.draw(window);
    }
        window.display();
    }

    

    return 0;
}

