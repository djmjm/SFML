#ifndef IMAGE_H
#define IMAGE_H

#include <SFML/Graphics.hpp>
#include "LAYER.h"
#include "MOUSE.h"

class IMAGE
{
public:
    IMAGE();
    IMAGE(int posx, int posy, int width, int height, char *texture, bool action);
    ~IMAGE();
    
    void setPos(sf::Vector2f pos);
    bool colisitionImage(sf::RenderWindow *window, MOUSE *mouses, LAYER *layer);
    void actionImage(MOUSE *mouses, int *mouse, sf::RenderWindow *window);
    void showImage(sf::RenderWindow *window);
    
    sf::Sprite image;
    bool imageActivate;
    int posx, posy;
    int width;
    int height;

protected:

    sf::Texture texture;
    bool action;
    bool colision;
    
    sf::RectangleShape blackBack;

};

#endif // IMAGE_H
