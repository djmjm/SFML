#include "BUTTON.h"

// It creates a simple button

BUTTON::BUTTON(int x, int y, int height, int width, char *button1, char *button2)
{
    this->height = height;
    this->width = width;
    
    this->TButton.loadFromFile(button1);
    this->TButton1.loadFromFile(button2);
    
    this->SButton.setPosition(x, y);
    this->SButton.setTexture(this->TButton1);
    
    this->buttonActive = false;
    
}

BUTTON::~BUTTON()
{
}

void BUTTON::showButton(sf::RenderWindow *window, LAYER *layer, int *mouse){
    
    window->draw(this->SButton);

}

void BUTTON::changePos(int x, int y){
    
    sf::Vector2f pos;
    
    pos.x = x - this->width;
    pos.y = y - this->height;
    
    this->SButton.setPosition(pos);
        
    
}

bool BUTTON::colision(sf::RenderWindow *window){
    
    sf::Vector2f pos;
    pos = this->SButton.getPosition();
    
    sf::Vector2i posMouse;
    posMouse = sf::Mouse::getPosition(*window);
    
    if( (posMouse.x > pos.x) && (posMouse.x < pos.x + this->width) && (posMouse.y > pos.y) && (posMouse.y < pos.y + this->height) )
        return true;
    else return false;
    
}


bool BUTTON::buttonClick(){
    return !this->buttonActive;
}

bool BUTTON::buttonGet(){
    return this->buttonActive;
}

void BUTTON::buttonAction(sf::RenderWindow *window, LAYER *layer, int *mouse, MOUSE *mouses){
    
    if (this->colision(window)){
        if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) && (*mouse == 0) ){
            this->buttonActive = this->buttonClick();
            *mouse = 1;
            mouses->setTexture(0);
        } else {
            mouses->setTexture(2);
        }
        this->SButton.setTexture(this->TButton);
        layer->setLayer(2);
    }
    else {
        this->SButton.setTexture(this->TButton1);
    }
}
