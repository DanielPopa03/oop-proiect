#include "../headere/Pizzeria.h"

int Pizzeria::run(){
    /* interfaceMode shows us what interface must be drawn on 
    screen and what event should be posible
    interface = 0 we add products in the baskets
    interface = 1 we can see the products that are in the basket
    and can also proceed to the check out
    interface = 2 we add the client details
    interface = 3 we see the receipt and also receipt
    is printed in a pdf format
    interface = 4 we thanks the client for shopping with us
    and we close the application
    */
    int interfaceMode = 0;

    // we add the products in here
    Basket basket;
 
    //we create the window in which we can drawn the interfaces
    sf::RenderWindow window(sf::VideoMode(800, 800), "Dorel Pizza");
    window.setFramerateLimit(60);

    //we load the font we will need to print text on our window
    sf::Font font;
    font.loadFromFile("DejaVuMathTeXGyre.ttf"); 

        
    //the button which manage what products can customers order
    std::vector<Buton> mainButtons;
    mainButtons.emplace_back(font, "Pizza Margerita", sf::Vector2f(100, 100));
    mainButtons.emplace_back(font, "Pizza Casei", sf::Vector2f(100, 160));
    mainButtons.emplace_back(font, "Chicken Kebab", sf::Vector2f(100, 220));
    mainButtons.emplace_back(font, "Beef Kebab", sf::Vector2f(100, 280));
    mainButtons.emplace_back(font, "Pizza Kebab", sf::Vector2f(100, 340));
    int selectedMainButton = -1;//helper variable that allowes us
    //to know what 

    //Basket button which allow the user to go to the basket interface
    //(interface = 0 -> 1) to see what products are in the baskert
    buton_Basket butonBasket("imagine.png",sf::Vector2f(700,0));
    
    // Basket button (showed in interfaceMode = 1) allowes
    //the user to close the basket interface
    buton_Basket inBasket("inchide.png", sf::Vector2f(700,0));
     
    ///button which is used in the check out proceedure
    //(interface 1->2->3->4) 
    buton_Basket butonNext("next.png",sf::Vector2f(700,700));
    

    // Submenu is the interface in which you can choose 
    //what size of the product you want
    Submenu submenu(font, sf::Vector2f(300, 200));
    int selectedSubmenuOption;
    bool submenuOpen = false;

    //variable used to get the number of products
    // the client needs
    std::string numberInput = "";
    int enteredNumber;
    

    
    //Client interface
    Client_builder C("n.png",font,sf::Vector2f(300,200));
    std::string Input = "";
    Client cl;
    //Order interface
    std::shared_ptr <Order> order = nullptr;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            switch(interfaceMode){
            case 0:{
                        if (event.type == sf::Event::MouseButtonPressed){
                            
                            sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                            // open and closes the basket menu
                            if(butonBasket.contains(mousePos) && !submenuOpen ){
                            interfaceMode ++;       
                            }
                            
                            if (!submenuOpen) {
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
                        if (submenuOpen && event.type == sf::Event::TextEntered) {
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                                try {
                                    if (numberInput != "") {
                                        submenuOpen = false; submenu.setInput(false);
                                        enteredNumber = std::stoi(numberInput);
                                        basket.adInBasket(selectedMainButton, selectedSubmenuOption, enteredNumber,"inchide.png" , 
                                        font, sf::Vector2f(200,100));
                                        numberInput = "";submenu.setText(numberInput);//std::cout << basket;
                                        break;
                                    }
                                    else throw EnterException(window, font);
                                } catch(std::exception &e) {
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
                                    }else throw DeleteException(window, font);
                                }catch(std::exception &e){
                                    std::cerr << e.what();
                                }
                            }                  
                        }
                    }
                break;
                case 1:{
                    if (event.type == sf::Event::MouseButtonPressed){
                        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                        // if the basket menu is open it check whether any product was removed
                        basket.deletePr(mousePos);

                        //it check if the basket exit button was pressed
                        if( inBasket.contains(mousePos)){interfaceMode--;}

                        //it checks if the next button was check
                        if(butonNext.contains(mousePos)){
                            interfaceMode ++;
                        }
                    }          
                }break;
                case 2:{
                    if (event.type == sf::Event::MouseButtonPressed){
                        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                        if(butonNext.contains(mousePos) && C.ready()){
                            cl = C.build();
                            interfaceMode ++;
                        }
                        if(C.contains(mousePos)){
                        C.pushText(Input);
                        Input = "";
                        }
                    }
                    if(event.type == sf::Event::TextEntered){
                      if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
                                try{
                                    if(Input != ""){
                                        Input.pop_back();
                                        C.setText(Input);
                                    }else throw DeleteException(window, font);
                                }catch(std::exception &e){
                                    std::cerr << e.what();
                                }
                       }
                       else{
                        Input += static_cast<char>(event.text.unicode);
                        C.setText(Input);
                       }
                    }
                }break;
                case 3: {
                    
                    if(order == nullptr){
                    order = std::make_shared <Order>(font, sf::Vector2f(800, 800), basket, cl,"home delivery",(double)(basket.getGrandTotal() + 20.00));
                    }
                    
                    if (event.type == sf::Event::MouseButtonPressed){
                        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                        if(butonNext.contains(mousePos) && C.ready()){
                            order->printReceipt();
                            interfaceMode ++;
                        }
                    } 


                    // Handle mouse wheel scrolling
                    if (event.type == sf::Event::MouseWheelMoved) {
                        int delta = event.mouseWheel.delta;

                        // Handle scrolling up
                        if (delta !=0) {
                            order->moveSlide(delta);
                            
                        } 
                    }

                }break; 
                case 4: {
                  window.clear(sf::Color::White);
                sf::RectangleShape rect;
                rect.setSize(sf::Vector2f(340, 60));
                rect.setPosition(sf::Vector2f(300, 300));
                rect.setFillColor(sf::Color::Green);
                sf::Text text;
                text.setFont(font);
                text.setString("Thank you for your order!! ");
                text.setPosition(sf::Vector2f(300, 300));
                text.setCharacterSize(16);
                text.setFillColor(sf::Color::Red);
                
                window.draw(rect);
                window.draw(text);
                window.display();
                std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
                return 0;
                } break;
            }    
        }            
    window.clear(sf::Color::White);
    switch (interfaceMode)
    {
    case 0:
       for (auto& button : mainButtons) {
            button.draw(window);
        }
        
        butonBasket.draw(window);

        // Draw submenu if open
        if (submenuOpen) {
            submenu.draw(window);
            
        }
    break;
    case 1:
       inBasket.draw(window);
        basket.draw(window);
        butonNext.draw(window);
    break;
    case 2:
       C.draw(window);
       butonNext.draw(window);
    break;
    case 3:
        if(order)
        order->draw(window);
        butonNext.draw(window);
    break;
    }
        window.display();
    }
    
    return 0;
}