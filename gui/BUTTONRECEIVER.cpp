#include "BUTTONRECEIVER.h"

BUTTONRECEIVER::BUTTONRECEIVER(int x, int y, int width, int height){
    
    this->height = height;
    this->width = width;
    this->x = x;
    this->y = y;
    
    this->sButton.setPosition(x, y);
    
    this->received = false;
    
}

BUTTONRECEIVER::~BUTTONRECEIVER(){
    
}

void BUTTONRECEIVER::showReceiver(sf::RenderWindow *window){
    
    window->draw(this->sButton);
    
}

bool BUTTONRECEIVER::colisionReceiver(sf::RenderWindow *window, LAYER *layer, MOUSE *mouses){
    
    sf::Vector2f  posMouse = mouses->mouse.getPosition();
    
    if( (posMouse.x > this->x) && (posMouse.x < this->x + this->width) && (posMouse.y > this->y) && (posMouse.y < this->y + this->height) ){
        layer->setLayer(2);
        mouses->setTexture(3);
        return true;
    } else return false;
    
}
