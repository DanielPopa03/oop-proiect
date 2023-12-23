#include "../headere/pizza.h"
Pizza::Pizza(const std::string& name_, const std::string& size_, const std::vector < std::string > &ingredients_, double pret_,const std::string& crustType_, 
const std::string& toppings_) : Product(name_, size_, ingredients_,pret_), crustType{crustType_}, toppings{toppings_}{};

Pizza::Pizza(const Pizza& obj):Product(obj){

    this->toppings = obj.toppings;
    this->crustType = obj.crustType;
}

void Pizza::print(std::ostream& os, Product& dt){
    try{
    Pizza obj = dynamic_cast<Pizza&>(dt);
    os << obj.name << '/' << obj.size << '/';
    for(auto&i : obj.ingredients){
        os<< i << "/";
    }
    os << obj.price << "/" << obj.crustType << "/" << obj.toppings;
    } catch(const std::bad_cast& e){
        std::cerr << "Error in dynamic_cast: " << e.what() << std::endl;
        
    }
}

Pizza Pizza_factory::pizza_margerita(std::string size){
            double price;
            if(size.compare("Small")== 0){price = 25;}
            if(size.compare("Medium")== 0){price = 30;}
            if(size.compare("Large")== 0){price = 35;}
            std::vector <std::string> ingredients;
            ingredients.push_back("Special dough");
            ingredients.push_back("Tomatoes");
            ingredients.push_back("Cheese");
            ingredients.push_back("Basil");
            ingredients.push_back("Egg");
            ingredients.push_back("Butter");
            return Pizza("Pizza Margerita",size,ingredients,price,"soft","mozzarella and basil");
        };

Pizza Pizza_factory::pizza_casei(std::string size){
            double price;
            if(size.compare("Small")== 0){price = 25;}
            if(size.compare("Medium")== 0){price = 30;}
            if(size.compare("Large")== 0){price = 35;}
            std::vector <std::string> ingredients;
            ingredients.push_back("Special dough");
            ingredients.push_back("Tomatoes");
            ingredients.push_back("Cheese");
            ingredients.push_back("Cold cut");
            ingredients.push_back("Sausages");
            ingredients.push_back("Eggs");
            ingredients.push_back("Butter");
            return Pizza("Pizza Margerita",size,ingredients,price,"soft","mozzarella, cold cuts and sausages");
        };