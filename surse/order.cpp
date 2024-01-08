#include "../headere/order.h"

Order::Order(const sf::Font& font, const sf::Vector2f& windowSize, const Basket& Basket__,const Client& cl_, const std::string& methodOfDelivery_, 
        const double price_):Basket_(Basket__), cl(cl_), methodOfDelivery(methodOfDelivery_) ,price(price_){
    
      actualDispalyMode = 0;
      mode = 0;
      std::vector <sf::Text> aux; 
      sf::Text textAux;
      textAux.setFont(font);
      textAux.setCharacterSize(20);
      textAux.setFillColor(sf::Color::Black);
      textAux.setPosition(sf::Vector2f( 0 , 0));
      int cursorPositionX = 0;
     
      textAux.setString("Receipt");
      aux.push_back(textAux);
      cursorPositionX +=40;

      textAux.setString("----------------------------");
      textAux.setPosition(sf::Vector2f( 0 , 0 + cursorPositionX));
      aux.push_back(textAux);
      cursorPositionX +=40;

      textAux.setString("Name of Product | Quantity | Size   | Price");
      textAux.setPosition(sf::Vector2f( 0 , 0 + cursorPositionX));
      aux.push_back(textAux);
      cursorPositionX +=40;

      textAux.setString("----------------------------");
      textAux.setPosition(sf::Vector2f( 0 , 0 + cursorPositionX));
      aux.push_back(textAux);
      cursorPositionX +=40;
      for (int i = 0; i < Basket_.order.size(); ++i) {
        int quantity = 1;
        for(int j = i + 1; j < Basket_.order.size() ; ++j){
            if ( Basket_.order[i]->getName() == Basket_.order[j]->getName() &&
            Basket_.order[i]->getSize() == Basket_.order[j]->getSize() ){
                quantity += 1;
                i = j;
            } else break;
        } 

        if (cursorPositionX < windowSize.y){
            textAux.setString(Basket_.order[i]->getName() + " " + std::to_string(quantity) + " " + Basket_.order[i]->getSize() 
            + " " + std::to_string(Basket_.order[i]->getPrice()));
            textAux.setPosition(sf::Vector2f( 0, 0 + cursorPositionX ));
            aux.push_back(textAux);
            cursorPositionX +=40;
        }else{
            cursorPositionX = 0;
            mode += 1;
            text.push_back(aux);
            aux.clear();
            textAux.setString(Basket_.order[i]->getName() + " " + std::to_string(quantity) + " " + Basket_.order[i]->getSize() 
            + " " + std::to_string(Basket_.order[i]->getPrice()));
            textAux.setPosition(sf::Vector2f( 0 , 0 + cursorPositionX ));
            aux.push_back(textAux);
            cursorPositionX +=40;
        }

      }
      if(aux.size() != 0) {
        
        if(cursorPositionX + 40 < windowSize.x){
        textAux.setString("GrandTotal:" + std::to_string(Basket_.getGrandTotal()));
        textAux.setPosition(sf::Vector2f( 0 , 0 + cursorPositionX ));
        aux.push_back(textAux);    
        text.push_back(aux);
        mode += 1;
        }
        else{
        cursorPositionX = 0;
            mode += 1;
            text.push_back(aux);
            aux.clear();
            textAux.setString("GrandTotal:" + std::to_string(Basket_.getGrandTotal()));
            textAux.setPosition(sf::Vector2f( 0 , 0 + cursorPositionX ));
            aux.push_back(textAux);
            text.push_back(aux);
        mode += 1;
        }
      }
      
    };


void Order::draw(sf::RenderWindow& window){
    for(int  i = 0; i < text[actualDispalyMode].size(); ++i){
        window.draw(text[actualDispalyMode][i]);
    }

}

void Order::moveSlide(int delta){
        // Handle scrolling up
        if (delta < 0){
            if(actualDispalyMode < mode - 1){
                actualDispalyMode ++;
            }
        }
        // Handle scrolling down
        if (delta > 0) {
            if(actualDispalyMode > 0){
                actualDispalyMode --;
            }
        }
    }


void Order::printReceipt(){
    // Open the file in truncation mode (deletes everything)
    
    std::ofstream file("receipt.pdf", std::ios::out | std::ios::trunc );

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file " << "receipt.pdf" << std::endl;
        return ; // Return an error code
    }
    
   
    //file << "<<\n/Length " << totalLength << "\n>>\nstream\n";
    std::vector <std::string> arr;
    for (int i = 0; i < mode ; i++){
            for (int j = 0; j < text[i].size(); j++){
                std::string c = text[i][j].getString();
                arr.push_back("(" + c + ")");
            }
        }
    std::vector<std::wstring> content;
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    for(auto& i : arr){
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::wstring newWideString = converter.from_bytes(i);
        content.push_back(newWideString);
    }

    // Calculate the total length of the content
    size_t totalLength = 0;
    for (const auto& row : content) {
        // Convert the wide string to UTF-8
        std::string utf8Row = converter.to_bytes(row);
        totalLength += utf8Row.size();
    }

    // Add extra bytes for PDF syntax (e.g., BT, ET, Tf, Tj)
    totalLength += content.size() * 30;


     file << "%PDF-1.7\n";
    file << "1 0 obj\n";
    file << "<<\n/Type /Catalog\n/Pages 2 0 R\n>>\nendobj\n";
    file << "2 0 obj\n";
    file << "<<\n/Type /Pages\n/Kids [3 0 R]\n/Count 1\n>>\nendobj\n";
    file << "3 0 obj\n";
    file << "<<\n/Type /Page\n/Parent 2 0 R\n/MediaBox [0 0 612 792]\n/Resources << /Font << /F1 4 0 R >> >>\n/Contents 5 0 R\n>>\nendobj\n";
    file << "4 0 obj\n";
    file << "<<\n/Type /Font\n/Subtype /Type1\n/BaseFont /Helvetica\n/Name /F1\n>>\nendobj\n";
    file << "5 0 obj\n";
    file << "<<\n/Length " << totalLength << "\n>>\nstream\n";

    size_t offset = 0;
    int aux = 750;
    for (const auto& row : content) {
        // Convert the wide string to UTF-8
        std::string utf8Row = converter.to_bytes(row);
        file << "BT\n/F1 12 Tf\n50 "<<aux<<" Td\n" << utf8Row << " Tj\nET\n";
        offset += utf8Row.size() + 30;  // Extra bytes for PDF syntax
        aux -= 20;
    }

    file << "endstream\nendobj\n";
    file << "xref\n0 6\n0000000000 65535 f\n0000000015 00000 n\n0000000077 00000 n\n0000000123 00000 n\n0000000271 00000 n\n0000000573 00000 n\n";
    file << "trailer\n<<\n/Size 6\n/Root 1 0 R\n>>\nstartxref\n";

    // Calculate the start offset of the cross-reference table
    size_t startxrefOffset = totalLength + 144;  // Offset after the last endobj
    file << startxrefOffset << "\n%%EOF";

    // Close the file
    file.close();

    std::cout << "PDF file created successfully "<< std::endl;
    file.close();
}