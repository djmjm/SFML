#include <SFML/Graphics.hpp>
#include "RealGui.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int main()
{
    sf::Texture TNull;
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "DJM's foot");
    
    BUTTONHANDLE moeda1[8] =
    {
        BUTTONHANDLE(10, 10, 0, 0, 0, 0, 36, 36, "images/testInventory/ouro.png", 5),
        BUTTONHANDLE(120, 200, 0, 0, 0, 0, 36, 36, "images/testInventory/espada.png", 5),
        BUTTONHANDLE(222, 50, 0, 0, 0, 0, 36, 36, "images/testInventory/ouro.png", 5),
        BUTTONHANDLE(400, 90, 0, 0, 0, 0, 36, 36, "images/testInventory/espada.png", 5),
        BUTTONHANDLE(50, 50, 0, 0, 0, 0, 36, 36, "images/testInventory/ouro.png", 5),
        BUTTONHANDLE(300, 100, 0, 0, 0, 0, 36, 36, "images/testInventory/espada.png", 5),
        BUTTONHANDLE(90, 20, 0, 0, 0, 0, 36, 36, "images/testInventory/ouro.png", 5),
        BUTTONHANDLE(150, 280, 0, 0, 0, 0, 36, 36, "images/testInventory/espada.png", 5),
    };
    
    IMAGE uniInventory(100, 270, 600, 300, "images/testInventory/inventoryUni2.png", 0);
    
    BUTTONRECEIVER button1[8] = {
        
        BUTTONRECEIVER(273, 493, 40, 40),
        BUTTONRECEIVER(323, 493, 40, 40),
        BUTTONRECEIVER(378, 493, 40, 40),
        BUTTONRECEIVER(431, 493, 40, 40),
        BUTTONRECEIVER(334, 548, 40, 40),
        BUTTONRECEIVER(385, 548, 40, 40),
        BUTTONRECEIVER(438, 548, 40, 40),
        BUTTONRECEIVER(489, 548, 40, 40)
    };
    
   int mouse = 0;
   KEYBOARD keyboard;
   
   LAYER layer;
   
   MOUSE mouses(&window);
   
   
   board vetorQuadrados[1] = { 
       board(1, 300, 604, 100, 270, sf::Color(232, 209, 17, 0), sf::Color(111, 111, 111, 0), sf::Color( 111, 111, 111, 0), sf::Color( 111, 111, 111, 0), false, false, 0, 1, 0, 0, 0, 0)
   };
   
   vetorQuadrados[0].setImage(uniInventory, 0);
   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(111,111,111,255));

        sortBoard(vetorQuadrados, 1, &window, &layer, &mouse, &mouses, &keyboard);
       
       
       for(int i = 0; i < 8; i++){
           for(int k = 0; k < 8; k++){
               
                moeda1[k].showButton(&window);
                moeda1[k].action(&window, &layer, &mouse, &mouses);
               
                button1[i].showReceiver(&window);
                if( (moeda1[k].getActive()) && (button1[i].colisionReceiver(&window, &layer, &mouses)) && !button1[i].received ){
                    button1[i].sButton.setTexture(*moeda1[k].sButton.getTexture());
                    moeda1[k].setReceived(true);
                    button1[i].received = true;
                    moeda1[k].setActive(false);
                    button1[i].idReceived = k;
                }
       
                if( (button1[i].received) && (button1[i].colisionReceiver(&window, &layer, &mouses)) && (sf::Mouse::isButtonPressed(sf::Mouse::Right)) ){
                    moeda1[button1[i].idReceived].setReceived(false);
                    button1[i].sButton.setTexture(TNull);
                    button1[i].received = false;
                }
            
           }
       
       }
           
       
        mouses.showMouse(&window);
        
        window.display();
        
    }

    return 0;
}
