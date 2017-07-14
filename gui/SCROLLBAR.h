#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "BUTTON.h"
#include "LAYER.h"
#include "MOUSE.h"
#include "BUTTONHANDLE.h"
#include "TEXTING.h"
#include <string.h>

class SCROLLBAR
{
public:
    SCROLLBAR(int x, int y, int nTexts, int mTexts, int nStrings);
    SCROLLBAR();
    ~SCROLLBAR();
    
    void showScroll(sf::RenderWindow *window, LAYER *layer, int *mouse);
    void action(sf::RenderWindow *window, LAYER *layer, MOUSE *mouses, int *mouse);
    void setPos(int x, int y);
    void setString(char *string, int pos, int m);
    void setId(int id, int pos, int m);
    void setTexts(int x, int y, int differenceY, int differenceX, int type, int width, int charSize, sf::Color color1, sf::Color color2, sf::Color backSelect);
    void compareTextsAndStrings();
    void setnStrings(int n);
    int getnStrings();
    void balanceChoose();
    
    double x, y;
    
protected:

    BUTTON *up;
    BUTTON *down;
    BUTTONHANDLE *midle;
    
    TEXTING **texts;
    
    int idChoose;
    
    int nTexts;
    int mTexts;
    int nStrings;
    
    char ***strings;
    int *id;
    
    sf::Vector2f diferencaDown;
    sf::Vector2f **diferencaAmongTexts;
    
    int scroolPos;
    
    double diferencatexts;

};

#endif // SCROLLBAR_H
