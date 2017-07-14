#ifndef BUTTONHANDLE_H
#define BUTTONHANDLE_H

#include <SFML/Graphics.hpp>
#include "LAYER.h"
#include "MOUSE.h"

class BUTTONHANDLE
{
public:
    BUTTONHANDLE();
    BUTTONHANDLE(int x, int y, double posMinX, double posMinY, double posMaxX, double posMaxY, int width, int height, char *texture, int type);
    ~BUTTONHANDLE();
    void setPos(double x, double y);
    void setPosMinMax(double x, double y);
    void showButton(sf::RenderWindow *window);
    bool colision(sf::RenderWindow *window, LAYER *layer, MOUSE *mouses);
    void action(sf::RenderWindow *window, LAYER *layer, int *mouse, MOUSE *mouses);
    double returnY();
    double returnX();
    bool getActive();
    void setActive(bool active);
    void setReceived(bool received);
    bool getReceived();
    
    int width, height;
    
    int diferencaMinY;
    int diferencaMaxY;
    
    sf::Vector2f diferencaBoard;
    sf::Vector2f diferencaBoardOld;
    
    int x, y;
    
    double posMinY;
    double posMaxY;
    double posMaxX;
    double posMinX;
    
    sf::Vector2f origin;
    
    
    double diferencaMinMax[4];
    
    sf::Sprite sButton;
    
protected:

    bool received;
    bool active;
    int type;
    sf::Texture tButton;

};

#endif // BUTTONHANDLE_H
