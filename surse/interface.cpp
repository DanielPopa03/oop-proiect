#include "../headere/interface.h"

buton_Basket::buton_Basket(const std::string& caleSpreImagine,const sf::Vector2f& position){
    if (!imagine.loadFromFile(caleSpreImagine)) {
        std::cout<<"Eroare incarcare imagine";
    }
    sf::Sprite aux(imagine);
    textura = aux;
    textura.setPosition(position);
    sf::FloatRect buttonBounds = textura.getGlobalBounds(); 
}

void buton_Basket::draw(sf::RenderWindow& window){
        window.draw(textura);
}
////////////////////////////////////////////////////////////////////////////////

Buton::Buton(const sf::Font& font, const std::string& label, const sf::Vector2f& position) {
    
    rect.setSize(sf::Vector2f(200, 40));
    rect.setPosition(position);
    rect.setFillColor(sf::Color::Blue);

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Black);

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.width / 2, textBounds.height / 2);
    text.setPosition(position.x + rect.getSize().x / 2, position.y + rect.getSize().y / 2);
}



void Buton::draw(sf::RenderWindow& window) {
            window.draw(rect);
            window.draw(text);
        }

////////////////////////////////////////////////////////////////////////////////

Submenu::Submenu(const sf::Font& font, const sf::Vector2f& position) {
            inputNumber = false;
            rect.setSize(sf::Vector2f(300, 250));
            rect.setPosition(position);
            rect.setFillColor(sf::Color::Green);

            // Create submenu buttons
            buttons.emplace_back(font, "Mica", sf::Vector2f(position.x + 50, position.y + 30));
            buttons.emplace_back(font, "Medie", sf::Vector2f(position.x + 50, position.y + 90));
            buttons.emplace_back(font, "Mare", sf::Vector2f(position.x + 50, position.y + 150));

            text.setFont(font);
            text.setCharacterSize(20);
            text.setPosition(sf::Vector2f(position.x + 50, position.y + 60));
            text.setString("");
            text.setFillColor(sf::Color::Black);

            label.setFont(font);
            label.setCharacterSize(20);
            label.setPosition(sf::Vector2f(position.x + 50, position.y + 30));
            label.setString("Enter the quantity:");
            label.setFillColor(sf::Color::Black);

            rect2.setSize(sf::Vector2f(300, 250));
            rect2.setPosition(sf::Vector2f(position.x + 50, position.y + 30));
            rect2.setFillColor(sf::Color::Yellow);
        }

void Submenu::draw(sf::RenderWindow& window) {
            if(inputNumber == false){
            window.draw(rect);
            for (auto& button : buttons) {
                button.draw(window);
             }
            }
            else{
            window.draw(rect2);
            window.draw(text);
            window.draw(label);
            }
        }

int Submenu::checkButtonClicked(const sf::Vector2f& point) {
            for (int i = 0; i < buttons.size(); ++i) {
                if (buttons[i].contains(point)) {
                    return i;
                }
            }
            return -1;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/*butoaneProduseBasket::butoaneProduseBasket( const sf::Font& font, const std::string& caleSpreImagine, const sf::Vector2f& position, const Basket& obj ){
    Buton *aux1 ;
    buton_Basket *aux2;
    for(unsigned int i = 0; i < obj.produseComandate.size(); i++){
        std::cout<<"";
        
        //aux1 = new Buton(font, (obj.produseComandate[i]).getNume() + "," + (obj.produseComandate[i]).getMarime(), position);
        //aux2 = new buton_Basket(caleSpreImagine, position);
    }
    

}*/



