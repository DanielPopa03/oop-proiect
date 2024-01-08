#include "../headere/basket.h"


Basket::Basket(const Basket& obj){
        for (const auto& productPtr : obj.order) {
        this->order.push_back(productPtr); // Creating a new Product and storing its pointer
    }
        this->numberOfProducts = obj.numberOfProducts;
        this->grandTotal = obj.grandTotal;
         }
void Basket::adInBasket(int id_product, int size, int number, const std::string& imagePath, const sf::Font& font, const sf::Vector2f& position){
    
    switch (id_product)
    {
    case 0:
        switch (size)
        {
        case 0:
           
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Pizza>(Pizza_factory::pizza_margerita("Small")));
            (this->displayProduct).emplace_back(font, "Pizza Margerita Small", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 1:
            
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Pizza>(Pizza_factory::pizza_margerita("Medium")));
            (this->displayProduct).emplace_back(font, "Pizza Margerita Medium", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));

            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 2:
            
             for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Pizza>(Pizza_factory::pizza_margerita("Large")));
            (this->displayProduct).emplace_back(font, "Pizza Margerita Large", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));

            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        default:
            std::cout<<"Eroare";
            break;
        }
          
    break;
    case 1:
        switch (size)
        {
        case 0:
            
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Pizza>(Pizza_factory::pizza_margerita("Small")));
            (this->displayProduct).emplace_back(font, "Pizza Casei Small", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 1:
            
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Pizza>(Pizza_factory::pizza_margerita("Medium")));
            (this->displayProduct).emplace_back(font, "Pizza Casei Medium", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 2:
            
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Pizza>(Pizza_factory::pizza_margerita("Large")));
            (this->displayProduct).emplace_back(font, "Pizza Casei Large", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        default:
            std::cout<<"Eroare";
            break;
        }

        break;
    case 2:
        switch (size)
        {
        case 0:
            
           for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Kebab>(Kebab_factory::Chicken_Kebab("Small")));
            (this->displayProduct).emplace_back(font, "Chicken Kebab Small", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            };
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;    
        case 1:
            
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Kebab>(Kebab_factory::Chicken_Kebab("Medium")));
            (this->displayProduct).emplace_back(font, "Chicken Kebab Medium", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 2:
            
           for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Kebab>(Kebab_factory::Chicken_Kebab("Large")));
            (this->displayProduct).emplace_back(font, "Chicken Kebab Large", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        default:
            std::cout<<"Eroare";
            break;
        }
        break;
    case 3:
        switch (size)
        {
        case 0:
            
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Kebab>(Kebab_factory::Beef_Kebab("Small")));
            (this->displayProduct).emplace_back(font, "Beef Kebab Small", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 1:
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Kebab>(Kebab_factory::Beef_Kebab("Medium")));
            (this->displayProduct).emplace_back(font, "Beef Kebab Medium", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 2:
            
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<Kebab>(Kebab_factory::Beef_Kebab("Large")));
            (this->displayProduct).emplace_back(font, "Beef Kebab Large", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        default:
            std::cout<<"Eroare";
            break;
        }
        break;
    case 4:
        switch (size)
        {
        case 0:
            
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<PizzaKebab>(PizzaKebab_factory::PizzaKebabc("Small")));
            (this->displayProduct).emplace_back(font, "PizzaKebab Small", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 1:
          
            for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<PizzaKebab>(PizzaKebab_factory::PizzaKebabc("Medium")));
            (this->displayProduct).emplace_back(font, "PizzaKebab Medium", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        case 2:
            
           for(int i=0; i < number; i++){
            (this->order).push_back(std::make_shared<PizzaKebab>(PizzaKebab_factory::PizzaKebabc("Large")));
            (this->displayProduct).emplace_back(font, "PizzaKebab Large", sf::Vector2f(position.x , position.y + 60 + 60*(numberOfProducts + i)));
            (this->deleteProduct).push_back(*new buton_Basket(imagePath, sf::Vector2f(position.x + 250,position.y + 60 + 60*(numberOfProducts + i))));
            }
            numberOfProducts += number;
            grandTotal += (this->order).back()->getPrice() * number;
        break;
        default:
            std::cout<<"Eroare";
            break;
        }
        break;
    default:
        std::cout<<"Eroare";
        break;
    }
   
};



void Basket::deleteFromProdus(int index ){
    this->numberOfProducts --;
    this->grandTotal -= (this->order)[index]->getPrice();
    (this->order).erase((this->order).begin()+index);
    for(unsigned int i = index+1; i < displayProduct.size(); ++i){
        (this->displayProduct)[i].move(sf::Vector2f(0,-60));
        (this->deleteProduct)[i].move(sf::Vector2f(0,-60));
    }
    (this->displayProduct).erase((this->displayProduct).begin()+index);
    (this->deleteProduct).erase((this->deleteProduct).begin()+index);
    
}

/**
 * docstring 
 * @param out 
*/
std::ostream& operator<<(std::ostream& out, const Basket& obj){
    out<<" [" << std::endl;
    for(unsigned int i = 0;i < obj.order.size();i++){
        out<< *(obj.order[i]);
        out<<", " << std::endl;
    }
    out<<" ]" << std::endl;
    out << obj.numberOfProducts << " " << obj.grandTotal << std::endl;
    return out;
}

Basket::~Basket() {
    order.clear();
    displayProduct.clear();
    deleteProduct.clear();
}

void Basket::draw(sf::RenderWindow& window){
    for(auto& i: displayProduct){
        i.draw(window);
    }
    for(auto& i: deleteProduct){
        i.draw(window);
    }
}

void Basket::deletePr(sf::Vector2f mousePos){
    for (unsigned i = 0; i < deleteProduct.size(); ++i) {
        if (deleteProduct[i].contains(mousePos)) {
        deleteFromProdus(i);
        break;
        }
}

}