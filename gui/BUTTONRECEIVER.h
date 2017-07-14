#ifndef BUTTONRECEIVER_H
#define BUTTONRECEIVER_H

#include <SFML/Graphics.hpp>
#include "LAYER.h"
#include "MOUSE.h"

class BUTTONRECEIVER
{
    
public:
        BUTTONRECEIVER(int x, int y, int width, int height);
        ~BUTTONRECEIVER();
        
        void showReceiver(sf::RenderWindow *window);
        bool colisionReceiver(sf::RenderWindow *window, LAYER *layer, MOUSE *mouses);
        
        int x, y;
        int width, height;
        
        sf::Sprite sButton;
        
        bool received;
        int idReceived;
        
protected:
    
    
};


#endif 