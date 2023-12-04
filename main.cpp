#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <string>
#include "headere/interface.h"
#include "headere/Product.h"
#include "headere/basket.h"
#include "headere/client.h"
#include "headere/order.h"
#include "headere/exception.h"



int main() {
    
    Basket _Basket;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Dorel Pizza");
    window.setFramerateLimit(60);

    
    sf::Font font;
    font.loadFromFile("DejaVuMathTeXGyre.ttf"); 

        

    std::vector<Buton> mainButtons;
    mainButtons.emplace_back(font, "Pizza Margerita", sf::Vector2f(100, 100));
    mainButtons.emplace_back(font, "Pizza Casei", sf::Vector2f(100, 160));
    mainButtons.emplace_back(font, "Chicken Kebab", sf::Vector2f(100, 220));
    mainButtons.emplace_back(font, "Beef Kebab", sf::Vector2f(100, 280));
    mainButtons.emplace_back(font, "Pizza Kebab", sf::Vector2f(100, 340));
    
    //Buton Basket
    buton_Basket butonBasket("imagine.png",sf::Vector2f(700,0));
    bool butonBasketActiv = false;
    

    //Inchide Basket
    buton_Basket inBasket("inchide.png", sf::Vector2f(700,0));
     
    buton_Basket butonNext("next.png",sf::Vector2f(700,700));
    bool butonNextActiv = false;

    // Submenu variabile
    Submenu submenu(font, sf::Vector2f(300, 200));
    int selectedMainButton = -1;
    int selectedSubmenuOption;
    std::string numberInput = "";
    int enteredNumber;
   
    bool submenuOpen = false;
    //Client interface
    std::string nameInput = "";
    std::string adressInput = "";
    std::string phoneNumberInput = "";

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                
                sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                // open and closes the basket menu
                if(butonBasket.contains(mousePos) && !submenuOpen ){
                   //
                   butonBasketActiv = true;
                   butonNextActiv = true;
                   sf::Event cosEvent;

                   if (butonBasketActiv)
                   {
                      
                      //if( event.type == sf::Event::Closed){ window.close();}
                      if( inBasket.contains(mousePos)){ butonBasketActiv = false; butonNextActiv = false;}
                      
                   }
                   
                }
                // if the basket menu is open it check whether any product was removed
                if(butonBasketActiv){
                _Basket.deletePr(mousePos);
                }
                if(butonNextActiv && butonNext.contains(mousePos)){
                    std::cout<< "b" << std::endl;
                }
                if (!submenuOpen && !butonBasketActiv ) {
                    for (unsigned i = 0; i < mainButtons.size(); ++i) {
                        if (mainButtons[i].contains(mousePos)) {
                            selectedMainButton = i;//////!!!!!!!!!!!!
                            submenuOpen = true;
                            break;
                        }
                    }
                 } 
                
                if(submenuOpen){
                selectedSubmenuOption = submenu.checkButtonClicked(mousePos);
                if (selectedSubmenuOption != -1) {
                        submenu.setInput(true);
                }
               }

             } 
             if(submenuOpen && event.type == sf::Event::TextEntered){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    try{
                        if(numberInput != ""){
                        submenuOpen = false; submenu.setInput(false);
                        enteredNumber = std::stoi(numberInput);
                        _Basket.adInBasket(selectedMainButton, selectedSubmenuOption, enteredNumber,"inchide.png" , 
                        font, sf::Vector2f(200,100));
                        numberInput = "";submenu.setText(numberInput);std::cout<<_Basket;
                        break;
                        }
                        else throw EnterException();
                    }catch(std::exception &e){
                        std::cerr << e.what();
                    }
                }
                else if (std::isdigit(event.text.unicode)) {
                                        numberInput += static_cast<char>(event.text.unicode);
                                        submenu.setText(numberInput);
                                    } 
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
                    try{
                        if(numberInput != ""){
                            numberInput.pop_back();
                            submenu.setText(numberInput);
                        }else throw DeleteException();
                    }catch(std::exception &e){
                        std::cerr << e.what();
                    }
                }                  
             }
        }            
    window.clear(sf::Color::White);
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
        butonNext.draw(window);
    }
        window.display();
    }

    

    return 0;
}

