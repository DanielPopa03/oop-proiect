#include "../headere/client.h"

std::ostream& operator<<(std::ostream& os, const Client& dt)
    {
    os <<std::endl<< dt.name << '/' << dt.address << '/' << dt.phoneNumber;
    return os;
    }

bool Client_builder::contains(const sf::Vector2f& point){
    if(textura.getGlobalBounds().contains(point) && mode < 3){
                mode +=1;
                switch (mode)
                {
                case 1:
                 name(text.getString());
                 label.setString("Enter your address:");
                 text.setString("");
                 break;
                case 2:
                 address(text.getString());
                 label.setString("Enter your phoneNumber:");
                 text.setString("");
                 break;
                case 3:
                phoneNumber(text.getString());
                label.setString("Proceed to the next stage ->");
                 text.setString("");
                break;
                }
                return 1;
            } else return 0;
}; 

void Client_builder::pushText(const std::string& text){
    switch (this->mode)
                {
                case 1:
                 name(text);
                 break;
                case 2:
                 address(text);
                 break;
                case 3:
                phoneNumber(text);
                break;
                }
};