#ifndef MOUSE_H
#define MOUSE_H

#include <SFML/Graphics.hpp>

class MOUSE
{
public:
    MOUSE(sf::RenderWindow *window);
    ~MOUSE();
    
    void showMouse(sf::RenderWindow *window);
    void setTexture(int number);
    
    sf::Sprite mouse;
    
protected:
    sf::Texture Tmouse;
    sf::Texture TmouseBeam;
    sf::Texture TmouseHand;
    sf::Texture TmouseHand2;

};

#endif // MOUSE_H
