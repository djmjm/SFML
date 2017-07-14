#ifndef BOARD_H
#define BOARD_H

// It creates some types of windows

#include <SFML/Graphics.hpp>
#include "BUTTON.h"
#include "LAYER.h"
#include "TEXTING.h"
#include "IMAGE.h"
#include <string.h>
#include "SCROLLBAR.h"
#include "INPUT.h"
#include "KEYBOARD.h"
#include "BUTTONHANDLE.h"


class board
{
public:

// no text, only window
    board(int id, int width, int height, int xX, int yY, sf::Color colorOutline, sf::Color color1, sf::Color color2, sf::Color color3, bool mover, bool window, int nTexts, int nImages, int nRectangles, int nScrollBars, int nInput, int nButtonHandle);
    
    ~board();
    void showBoard(sf::RenderWindow *window, LAYER *layer, int *mouse);
    bool colisionBoard(sf::RenderWindow *window, LAYER *layer, int *mouse);
    void moveBoard(sf::RenderWindow *window, LAYER *layer);
    bool getMouseClicou();
    void actionBoard(sf::RenderWindow *window, LAYER *layer, int *mouse, MOUSE *mouses, KEYBOARD *keyboard);
    int getId();
    bool getClose();
    void setClose(bool close);
    void setCanMove(bool canMove);
    void setFirst(bool first);
    void setText(TEXTING text, int pos, bool order);
    void setImage(IMAGE image, int pos);
    void setRectangle(sf::RectangleShape rectangle, int pos);
    void setScrollBar(SCROLLBAR scrollbar, int pos);
    void setInput(INPUT input, int pos);
    void setButtonHandle(BUTTONHANDLE button, int pos);
    
    INPUT *inputs;
    sf::Vector2f *diferencaRectangle;
    sf::Vector2f *diferencaImage;
    sf::Vector2f *diferencatext;
    sf::Vector2f *diferencaScroll;
    sf::Vector2f *diferencaInput;
    sf::Vector2f *diferencaButtonHandle;
    
    BUTTON *botaoFechar;// = { BUTTON(this->posX, this->posY, 25, 26, "images/Button1.png", "images/Button2.png") };
    TEXTING *texts ;//= { TEXTING(this->posX, this->posY, "dsd", "dsds", 1, 20, sf::Color(169, 169, 169, 255), sf::Color(169, 169, 169, 255), sf::Color(169, 169, 169, 255) ) };
    SCROLLBAR *scrollBars;
    sf::RectangleShape *rectangles;
    IMAGE *images;
    BUTTONHANDLE *buttonsHandle;
    
protected:

    sf::RectangleShape retangulo;
    sf::RectangleShape retangulo1;
    sf::RectangleShape retangulo2;
    
    int posX;
    int posY;
    int width;
    int height;
    
    bool mouseClicou;
    
    sf::Font font1;
    sf::Text text1;
    
    bool mover;
    bool Bwindow;
    bool canMove;
    
    bool close;
    bool first;
    
    int nButtonHandle;
    int nImages;
    int ntexts;
    int nRectangles;
    int nScrollBars;
    int nInput;
    
    char strin[12];
    
    int layer;
    
    int id;
    
    bool difFirst;

};

void sortBoard(board *boards, int number, sf::RenderWindow *window, LAYER *layer, int *mouse, MOUSE *mouses, KEYBOARD *keyboard);


#endif // BOARD_H
