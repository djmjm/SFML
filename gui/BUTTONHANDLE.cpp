#include "BUTTONHANDLE.h"

BUTTONHANDLE::BUTTONHANDLE(){
    
}

BUTTONHANDLE::BUTTONHANDLE(int x, int y, double posMinX, double posMinY, double posMaxX, double posMaxY, int width, int height, char *texture, int type)
{
    this->height = height;
    this->width = width;
    
    this->x = x;
    this->y = y;
    
    this->received = false;
    
    this->origin.x = x;
    this->origin.y = y;
    
    this->tButton.loadFromFile(texture);
    this->sButton.setTexture(this->tButton);
    this->sButton.setPosition(x, y);
    
    this->type = type;
    this->active = false;
    
    this->posMaxY = posMaxY;
    this->posMinY = posMinY;
    this->posMaxX = posMaxX;
    this->posMinX = posMinX;
    
}

BUTTONHANDLE::~BUTTONHANDLE()
{
}

void BUTTONHANDLE::setPos(double x, double y){
        
        this->sButton.setPosition(x, y);
        this->x = x;
        this->y = y;
    
}

void BUTTONHANDLE::setPosMinMax(double x, double y){
    
        this->posMinY = y + this->diferencaMinMax[0];
        this->posMaxY = y + this->diferencaMinMax[1];
        this->posMinX = x + this->diferencaMinMax[2];
        this->posMaxX = x + this->diferencaMinMax[3];
}

void BUTTONHANDLE::showButton(sf::RenderWindow *window){
    
    if (!this->received)
        window->draw(this->sButton);
    
}

bool BUTTONHANDLE::colision(sf::RenderWindow *window, LAYER *layer, MOUSE *mouses){
    sf::Vector2f  posMouse = mouses->mouse.getPosition();
    sf::Vector2f  posButton = this->sButton.getPosition();
    
    if( (posMouse.x > posButton.x) && (posMouse.x < posButton.x + this->width) && (posMouse.y > posButton.y) && (posMouse.y < posButton.y + this->height) && !this->received ){
        layer->setLayer(2);
        mouses->setTexture(3);
        return true;
    } else return false;
    
}

void BUTTONHANDLE::action(sf::RenderWindow *window, LAYER *layer, int *mouse, MOUSE *mouses){
    
    sf::Vector2f  posMouse = mouses->mouse.getPosition();
    sf::Vector2f posButton = this->sButton.getPosition();
    
    if(this->colision(window, layer, mouses)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && (*mouse == 0)){
            this->active = true;
            *mouse = 1;
        }
    }
    
    if(this->active){
        if(type == 3){
            if( (posMouse.y < this->posMaxY) && (posMouse.y > this->posMinY) ){
                this->setPos(posButton.x, posMouse.y);
            }
        } else if(type == 2){
            if( (posMouse.y > this->posMinY) && (posMouse.y < this->posMaxY) && (posMouse.x > this->posMinX) && (posMouse.x < this->posMaxX) ){
                
                this->setPos(posMouse.x, posMouse.y);
                this->diferencaBoardOld.x = posMouse.x;
                this->diferencaBoardOld.y = posMouse.y;
                
            }
            
        } else if( (type == 5) && (!this->received) ){
            
            this->setPos(posMouse.x, posMouse.y);
            
        }
    }
    
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        this->active = false;
        this->diferencaBoardOld.x = this->diferencaBoard.x;
        this->diferencaBoardOld.y = this->diferencaBoard.y;
        
        if(this->type == 5){
            this->setPos(this->origin.x, this->origin.y);
        }
        
    }
    
}

double BUTTONHANDLE::returnY(){
    sf::Vector2f pos = this->sButton.getPosition();
    
    return pos.y;
}

double BUTTONHANDLE::returnX(){
    sf::Vector2f pos = this->sButton.getPosition();
    
    return pos.x;
}

bool BUTTONHANDLE::getActive(){
    
    return this->active;
    
}

void BUTTONHANDLE::setReceived(bool received){
    
    this->received = received;
    
}

bool BUTTONHANDLE::getReceived(){
    
    return this->received;
    
}

void BUTTONHANDLE::setActive(bool active){
    
    this->active = active;
    
}