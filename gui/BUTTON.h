#ifndef BUTTON_H
#define BUTTON_H

// It creates one simple button

#include <SFML/Graphics.hpp>
#include "LAYER.h"
#include "MOUSE.h"

class BUTTON
{
public:
    BUTTON(int x, int y, int height, int width, char *button1, char *button2);
    ~BUTTON();
    void showButton(sf::RenderWindow *window, LAYER *layer, int *mouse );
    void changePos(int x, int y);
    bool colision(sf::RenderWindow *window);
    bool buttonClick();
    bool buttonGet();
    void buttonAction(sf::RenderWindow *window, LAYER *layer, int *mouse, MOUSE *mouses);
    
    int height;
    int width;
    
protected:
    sf::Sprite SButton;
    sf::Texture TButton;
    sf::Texture TButton1;
    
    bool buttonActive;

};

#endif // BUTTON_H
