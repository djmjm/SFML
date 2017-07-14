#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include "MOUSE.h"
#include "LAYER.h"
#include <string.h>
#include "KEYBOARD.h"

class INPUT
{
public:
    INPUT();
    INPUT(int x, int y, int xSize, int ySize,int length, sf::Color color1, sf::Color colorBound);
    ~INPUT();
    void showInput(sf::RenderWindow *window);
    void setPos(int x, int y);
    bool colision(sf::RenderWindow *window, MOUSE *mouses, LAYER *layer);
    void action(sf::RenderWindow *window, MOUSE *mouses, LAYER *layer, int *mouse, KEYBOARD *keyboard);
    char presKey(KEYBOARD *keyboard);
    
    int length;
    int x, y;
    int xSize;
    int ySize;
    sf::Text text;
    char *string;
    bool active;
    int stringLenght;
    
protected:

    void equalString();

    sf::RectangleShape rectangle;
    
    char *aux;
    sf::Font font;

    sf::Color color1, colorBound;

};

#endif // INPUT_H
