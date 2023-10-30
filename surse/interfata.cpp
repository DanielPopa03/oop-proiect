#include "../headere/interfata.h"

buton_Cos::buton_Cos( const std::string& caleSpreImagine,const sf::Vector2f& position){
    if (!imagine.loadFromFile(caleSpreImagine)) {
        std::cout<<"Eroare incarcare imagine";
    }
    sf::Sprite aux(imagine);
    textura = aux;
    textura.setPosition(position);
    //sf::FloatRect buttonBounds = textura.getGlobalBounds(); 
}

void buton_Cos::draw(sf::RenderWindow& window){
        window.draw(textura);
}

Buton::Buton(const sf::Font& font, const std::string& label, const sf::Vector2f& position) {
    rect.setSize(sf::Vector2f(200, 40));
    rect.setPosition(position);
    rect.setFillColor(sf::Color::Blue);

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.width / 2, textBounds.height / 2);
    text.setPosition(position.x + rect.getSize().x / 2, position.y + rect.getSize().y / 2);
}

void Buton::draw(sf::RenderWindow& window) {
            window.draw(rect);
            window.draw(text);
        }

Submenu::Submenu(const sf::Font& font, const sf::Vector2f& position) {
            rect.setSize(sf::Vector2f(300, 250));
            rect.setPosition(position);
            rect.setFillColor(sf::Color::Green);

            // Create submenu buttons
            buttons.emplace_back(font, "Mica", sf::Vector2f(position.x + 50, position.y + 30));
            buttons.emplace_back(font, "Medie", sf::Vector2f(position.x + 50, position.y + 90));
            buttons.emplace_back(font, "Mare", sf::Vector2f(position.x + 50, position.y + 150));
        }

void Submenu::draw(sf::RenderWindow& window) {
            window.draw(rect);
            for (auto& button : buttons) {
                button.draw(window);
            }
        }

int Submenu::checkButtonClicked(const sf::Vector2f& point) {
            for (unsigned int i = 0; i < buttons.size(); ++i) {
                if (buttons[i].contains(point)) {
                    return i;
                }
            }
            return -1;
        }
