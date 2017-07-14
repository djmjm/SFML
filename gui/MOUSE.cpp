#include "MOUSE.h"

MOUSE::MOUSE(sf::RenderWindow *window)
{
    window->setMouseCursorVisible(false);
    
    this->Tmouse.loadFromFile("images/mouse.png");
    this->TmouseBeam.loadFromFile("images/mouseBeam.png");
    this->TmouseHand.loadFromFile("images/mouseHand.png");
    this->TmouseHand2.loadFromFile("images/mouseHand2.png");
    this->mouse.setTexture(this->Tmouse);
    
}

MOUSE::~MOUSE()
{
}

void MOUSE::showMouse(sf::RenderWindow *window){
    
    this->mouse.setPosition( (sf::Vector2f) (sf::Mouse::getPosition(*window)) );
    
    window->draw(this->mouse);
    
}


void MOUSE::setTexture(int number){
    
    if (number == 0){
        this->mouse.setTexture(this->Tmouse);
    } else if (number == 1){
        this->mouse.setTexture(this->TmouseBeam);
    } else if (number == 2){
        this->mouse.setTexture(this->TmouseHand);
    } else if (number == 3){
        this->mouse.setTexture(this->TmouseHand2);
    }
    
}
