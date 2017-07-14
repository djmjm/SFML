#include "KEYBOARD.h"

KEYBOARD::KEYBOARD()
{
}

KEYBOARD::~KEYBOARD()
{
}

void KEYBOARD::KeyboardCheckPressed(){
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) ){
            this->activeQ = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ){
            this->activeW = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::E)) ){
            this->activeE = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::R)) ){
            this->activeR = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::T)) ){
            this->activeT = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) ){
            this->activeY = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::U)) ){
            this->activeU = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::I)) ){
            this->activeI = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::O)) ){
            this->activeO = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::P)) ){
            this->activeP = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ){
            this->activeA = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ){
            this->activeS = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ){
            this->activeD = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::F)) ){
            this->activeF = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::G)) ){
            this->activeG = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::H)) ){
            this->activeH = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::J)) ){
            this->activeJ = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::K)) ){
            this->activeK = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::L)) ){
            this->activeL = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) ){
            this->activeZ = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::X)) ){
            this->activeX = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::C)) ){
            this->activeC = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::V)) ){
            this->activeV = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::B)) ){
            this->activeB = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::N)) ){
            this->activeN = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::M)) ){
            this->activeM = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) ){
            this->activeSpace = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) ){
            this->activeBackspace = false;
    }   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) ){
            this->activeEnter = false;
    }   
}
