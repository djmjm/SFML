#ifndef TEXTING_H
#define TEXTING_H

#include "MOUSE.h"
#include "LAYER.h"
#include <SFML/Graphics.hpp>
#include <string.h>

class TEXTING
{
public:
    TEXTING();
    TEXTING(int x, int y, char *string, char *font, int charSize, int width, sf::Color color1, sf::Color color2, sf::Color colorSelection, int type);
    ~TEXTING();
    void showText(sf::RenderWindow *window);
    void setWidth(int width);
    void sortText(char *strin);
    char *getString();
    bool colisionText(sf::RenderWindow *window, MOUSE *mouses, LAYER *layer);
    void actionText(MOUSE *mouses, int *mouse);
    void setPos(sf::Vector2f pos);
    void setText(int x, int y, char *string, char *font, int charSize, int width, sf::Color color1, sf::Color color2, sf::Color colorSelection, int type);
    bool textActivate;
    void setId(int id);
    int returnType();
    int returnId();
    bool returnClicou();
    void setClicou( bool clicou);
    void setChoose(bool choose);
    
    
    sf::Text text;
    sf::Font font1;
    int posX;
    int posY;
    int width;
    
protected:
    int height;
    int id;
    bool choose;
    bool clicou;
    char string[10000];
    int type;
    
    sf::Color color1, color2;
    
    sf::RectangleShape selection;
    
    sf::Texture *tSelection1;
    sf::Texture *tSelection2;
    
    sf::Sprite *SSelection;

};

#endif // TEXTING_H
