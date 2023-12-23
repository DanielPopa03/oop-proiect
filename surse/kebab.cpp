#include "../headere/kebab.h"


Kebab::Kebab(const std::string& name_, const std::string  & size_, const std::vector<std::string> &ingredients_, double price_,const std::string& typeOfMeat_):
Product(name_, size_, ingredients_,price_),typeOfMeat{typeOfMeat_}{}; 


Kebab::Kebab(const Kebab& obj):Product(obj){
    
   
    this->typeOfMeat = obj.typeOfMeat;
}

void Kebab::print(std::ostream& os, Product& dt){
   try{
    Kebab obj = dynamic_cast<Kebab&>(dt);
    os << obj.name << '/' << obj.size << '/';
    for(auto&i : obj.ingredients){
        os<< i << "/";
    }
    os << obj.price <<"/"<<obj.typeOfMeat;
    } catch(const std::bad_cast& e){
        std::cerr << "Error in dynamic_cast: " << e.what() << std::endl;
        throw;
    }
}

Kebab Kebab_factory::Chicken_Kebab(std::string size){
            double price;
            if(size.compare("Small")== 0){price = 25;}
            if(size.compare("Medium")== 0){price = 30;}
            if(size.compare("Large")== 0){price = 35;}
            std::vector <std::string> ingredients;
            ingredients.push_back("Pita");
            ingredients.push_back("Tomatoes");
            ingredients.push_back("Cucumbers");
            ingredients.push_back("Onion");
            ingredients.push_back("Peppers");
            ingredients.push_back("Chicken");
            return Kebab("Chicken Kebab",size,ingredients,price,"Chicken");
        };

Kebab Kebab_factory::Beef_Kebab(std::string size){
            double price;
            if(size.compare("Small") == 0){price = 25;}
            if(size.compare("Medium")== 0){price = 30;}
            if(size.compare("Large") == 0){price = 35;}
            std::vector <std::string> ingredients;
            ingredients.push_back("Pita");
            ingredients.push_back("Tomatoes");
            ingredients.push_back("Cucumbers");
            ingredients.push_back("Onion");
            ingredients.push_back("Peppers");
            ingredients.push_back("Beef");
            return Kebab("Beef Kebab",size,ingredients,price,"Beef");
        };