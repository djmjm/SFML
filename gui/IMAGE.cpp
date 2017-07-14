#include "IMAGE.h"

IMAGE::IMAGE()
{
}

IMAGE::IMAGE(int posx, int posy, int width, int height, char *texture, bool action)
{
    this->posx = posx;
    this->posy = posy;
    this->width = width;
    this->height = height;
    this->texture.loadFromFile(texture);
    this->image.setTexture(this->texture);
    this->image.setPosition(this->posx, this->posy);
    
    this->action = action;
    this->imageActivate = false;
    this->colision = false;
    
    this->blackBack.setFillColor( sf::Color(0, 0, 0, 230) );
    this->blackBack.setPosition(0, 0);
    
    sf::Vector2f size;
    
    size.x = 0;
    size.y = 0;
    
    this->blackBack.setSize(size);
    
}

IMAGE::~IMAGE()
{
}

void IMAGE::showImage(sf::RenderWindow *window){
    
    window->draw(this->blackBack);
    window->draw(this->image);
    
}

bool IMAGE::colisitionImage(sf::RenderWindow *window, MOUSE *mouses, LAYER *layer){
    
    sf::Vector2f  posMouse = mouses->mouse.getPosition();
    sf::Vector2f  posImage = this->image.getPosition();
    
    if( (posMouse.x > posImage.x) && (posMouse.x < posImage.x + this->width) && (posMouse.y > posImage.y) && (posMouse.y < posImage.y + this->height) ){
        if(this->action){
            mouses->setTexture(2);
            layer->setLayer(2);
            return true;
        } else return false;
    } else {
        return false;
    }
    
}

void IMAGE::actionImage(MOUSE *mouses, int *mouse, sf::RenderWindow *window){
    
    sf::Vector2f size;
    
    if( (this->imageActivate) && (sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) && (*mouse == 0) ){
    
        size.x = 2000;
        size.y = 2000;
    
        this->blackBack.setSize(size);
        
        *mouse = 1;
    } 
    
    if(sf::Mouse::isButtonPressed( sf::Mouse::Right ) ){ 
        this->imageActivate = false;   
        size.x = 0;
        size.y = 0;
    
        this->blackBack.setSize(size);
        
        *mouse = 1;
        
    }
    
}

void IMAGE::setPos(sf::Vector2f pos){
    this->image.setPosition(pos);
}
