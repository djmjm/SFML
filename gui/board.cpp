#include "board.h"

// It creates some types of windows

// no text, only board
board::board(int id, int width, int height, int xX, int yY, sf::Color colorOutline, sf::Color color1, sf::Color color2, sf::Color color3, bool mover, bool window, int nTexts, int nImages, int nRectangles, int nScrollBars, int nInput, int nButtonHandle)
{
// Creating buttons Handle

    this->nButtonHandle = nButtonHandle;
    
    this->buttonsHandle = new BUTTONHANDLE[nButtonHandle];
    this->diferencaButtonHandle = new sf::Vector2f[nButtonHandle];
    
// creating inputs
    this->inputs = new INPUT[nInput];
    this->nInput = nInput;

    this->diferencaInput = new sf::Vector2f[nInput];
    
// creating scrollBars

    this->scrollBars = new SCROLLBAR[nScrollBars];
    this->diferencaScroll = new sf::Vector2f[nScrollBars];
    
    this->nScrollBars = nScrollBars;
    
// creating rectangles
    this->rectangles = new sf::RectangleShape[nRectangles];
    this->diferencaRectangle = new sf::Vector2f[nRectangles];
    
    this->nRectangles = nRectangles;
    
// creating images
    this->images = new IMAGE[nImages];
    this->diferencaImage = new sf::Vector2f[nImages];
    
    this->nImages = nImages;
    
// creating texts
    this->texts = new TEXTING[nTexts];
    this->diferencatext = new sf::Vector2f[nTexts];
    
// creating button
    if(window)
        this->botaoFechar = new BUTTON(this->posX, this->posY, 25, 26, "images/Button1.png", "images/Button2.png");
    else this->botaoFechar = new BUTTON(-100, -100, 25, 26, "images/Button1.png", "images/Button2.png");
    
    this->layer = 1;
    
    this->ntexts = nTexts;
    
    this->first = false;
    
    this->id = id;
    this->close = false;
    this->posX = xX;
    this->posY = yY;
    this->mover = mover;
    
    this->font1.loadFromFile("font1.ttf");
    
    this->text1.setFont(this->font1);
    this->text1.setColor(sf::Color::Black);
    this->text1.setPosition(this->posX + 10, this->posY + 10);
    this->text1.setCharacterSize(11);
    
    sf::Vector2f xy;
    
    xy.x = width;
    xy.y = height;
    
//up part of board

    this->retangulo.setOutlineThickness(2);
    this->retangulo.setOutlineColor(colorOutline);
    this->retangulo.setFillColor(color1);
    this->retangulo.setSize(xy);
    this->retangulo.setPosition(xX, yY);
    
// down part of board
    
    xy.y = xy.y/2;
    
    this->retangulo1.setFillColor(color2);
    this->retangulo1.setSize(xy);
    this->retangulo1.setPosition(xX, yY);
    
// between part of board
    
    this->retangulo2.setPosition(xX, yY + xy.y);
    
    xy.y = xy.y/10;
    
    this->retangulo2.setFillColor(color3);
    this->retangulo2.setSize(xy);
    
    this->width = width;
    this->height = height;
    this->mouseClicou = false;
    
    this->Bwindow = window;
}


board::~board()
{
}

void board::showBoard(sf::RenderWindow *window, LAYER *layer, int *mouse){
    if (!close){
// show rectangles

        window->draw(this->retangulo);
        window->draw(this->retangulo1);
        window->draw(this->retangulo2);
        
        int i = 0;
        
        for(i = 0; i < this->nRectangles; i++){
            window->draw(this->rectangles[i]);
        }
    
//test close button
  
        if (this->Bwindow){
            this->botaoFechar->changePos(this->posX + this->width, this->posY + 25);
            this->botaoFechar->showButton(window, layer, mouse);
    
        }
        
// show inputs

        for(i = 0; i < this->nInput; i++){
            this->inputs[i].showInput(window);
        }
        
// show scrollbars

        for(i = 0; i < this->nScrollBars; i++){
            this->scrollBars[i].showScroll(window, layer, mouse);
        }
        
// show texts
        
        for(i = 0; i < this->ntexts;i++)
            this->texts[i].showText(window);
            
// show images

         for(i = 0; i < this->nImages;i++)
            this->images[i].showImage(window);   
            
// show Button Handle

        for(i = 0; i < this->nButtonHandle; i++){
            
            this->buttonsHandle[i].showButton(window);
            
        }
        
    }
}

void board::actionBoard(sf::RenderWindow *window, LAYER *layer, int *mouse, MOUSE *mouses, KEYBOARD *keyboard){
   if (!close){ 
       
       layer->setLayer(1);
       
       bool mouseActive = false;
       int i = 0;
       
    // button handle actions
    
    if(this->first){
        
        for(i = 0; i < this->nButtonHandle; i++){
            
            this->buttonsHandle[i].action(window, layer, mouse, mouses);
            
        }
        
    }
       
    // test keyboard click
    
    keyboard->KeyboardCheckPressed();
       
    // input actions
       
       if(this->first){
           for(i = 0; i < this->nInput; i++){
               this->inputs[i].action(window, mouses, layer, mouse, keyboard);
           }
       }
       
    // scroll actions   
       
       if(this->first){
            for(i = 0; i < this->nScrollBars; i++){
                this->scrollBars[i].action(window, layer, mouses, mouse);
            }
       }
       
    // test close button
        if (this->first){
            
            this->close = this->botaoFechar->buttonGet();
            this->botaoFechar->buttonAction(window, layer, mouse, mouses);
        }
        
        // check colision text and update textActivate
        if (this->first){
            int i = 0;
            if (*mouse == 0){
                for(i = 0; i < this->ntexts; i++)
                    this->texts[i].textActivate = this->texts[i].colisionText(window, mouses, layer);
            }
            for(i = 0; i < this->ntexts; i++){
                this->texts[i].colisionText(window, mouses, layer);
                this->texts[i].actionText(mouses, mouse);
            
            }
            
        }
        
        //Check colision images and update ImageActivate
        
        if (this->first){
            int i = 0;
            if (*mouse == 0){
                for(i = 0; i < this->nImages; i++)
                    this->images[i].imageActivate = this->images[i].colisitionImage(window, mouses, layer);
            }
            for(i = 0; i < this->nImages; i++){
                this->images[i].imageActivate = this->images[i].colisitionImage(window, mouses, layer);
                this->images[i].actionImage(mouses, mouse, window);
            
            }
            
        }

    
    // test mouse click
        if ( !sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
            this->mouseClicou = false;
            *mouse = 0;
        }   
        
        if ( ( this->colisionBoard(window, layer, mouse) ) && (sf::Mouse::isButtonPressed(sf::Mouse::Left) ) && (*mouse == 0) ){
            this->mouseClicou = true;
            *mouse = 1;
        }
        
        
        if ( !this->colisionBoard(window, layer, mouse)  && (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (layer->getLayer() < 2) ){
            this->canMove = false;
            layer->setLayer(0);
        }
        
// Checking the text activity

        bool activeText = false;
        bool activeImage = false;
        
        for(i = 0; i < this->ntexts; i++){
                if (this->texts[i].textActivate == true)
                    activeText = true;
            
        }
        
        for(i = 0; i < this->nImages; i++){
                if (this->images[i].imageActivate == true)
                    activeImage = true;
            
        }
    
// move the window

        if ( ( (this->mover) && (this->canMove) && (layer->getLayer() == 1 ) && (!activeText) && (!activeImage) ) || ( (this->first) && (this->mover) && (layer->getLayer() == 1 ) && (!activeText) && (!activeImage) ) )
            moveBoard(window, layer);
    
        
// changing mouse cursor
        if(this->first)
            if(layer->getLayer() <= 1)
                mouses->setTexture(0); 
        
   }
}


bool board::colisionBoard(sf::RenderWindow *window, LAYER *layer, int *mouse){
    sf::Vector2f pos;
    pos = this->retangulo.getPosition();
    
    sf::Vector2i posMouse;
    posMouse = sf::Mouse::getPosition(*window);
    
// check the layer number && canMove
    
    if( (posMouse.x > pos.x) && (posMouse.x < pos.x + this->width) && (posMouse.y > pos.y) && (posMouse.y < pos.y + this->height) && (layer->getLayer() == 0 )  ){
       this->canMove = true;
        layer->setLayer(1);
    }
    
// check the mouse colision with rectangle
    
    if( (posMouse.x > pos.x) && (posMouse.x < pos.x + this->width) && (posMouse.y > pos.y) && (posMouse.y < pos.y + this->height) ){
        return true;
    }
    else {
        if(*mouse == 0)
            layer->setLayer(0);
        return false;
    }
    
    
    
}

void board::moveBoard(sf::RenderWindow *window, LAYER *layer){
    sf::Vector2i posMouse;
    posMouse = sf::Mouse::getPosition(*window);
    
    int i = 0;
    
    sf::Vector2f posNow;
    sf::Vector2f posText1Now[this->ntexts];
    sf::Vector2f posScrollNow[this->ntexts];
    sf::Vector2f posImageNow[this->nImages];
    sf::Vector2f posInputNow[this->nInput];
    sf::Vector2f posRectangleNow[this->nRectangles];
    sf::Vector2f diferenca[this->ntexts];
    sf::Vector2f posButtonHandleNow[this->nButtonHandle];
    
    posNow = this->retangulo.getPosition();
     sf::Vector2f oldPosNow = posNow;
    
    if (this->mouseClicou){
        
            posNow.x = posMouse.x - 10;
            posNow.y = posMouse.y - 10;
            
    }
    
// Update the movement position
    
    for(i = 0; i < this->nButtonHandle; i++){
        posButtonHandleNow[i].x = posNow.x + this->buttonsHandle[i].diferencaBoard.x;
        posButtonHandleNow[i].y = posNow.y + this->buttonsHandle[i].diferencaBoard.y;
    
        if(!this->buttonsHandle[i].getActive()){
            this->buttonsHandle[i].setPos(posButtonHandleNow[i].x, posButtonHandleNow[i].y);
            this->buttonsHandle[i].setPosMinMax(posNow.x, posNow.y);
            
        }
        else{
            this->buttonsHandle[i].diferencaBoard.x = this->buttonsHandle[i].diferencaBoardOld.x - posNow.x;
            this->buttonsHandle[i].diferencaBoard.y = this->buttonsHandle[i].diferencaBoardOld.y - posNow.y;
        }
    
    }
    
    for(i = 0; i < this->nInput; i++){
        posInputNow[i].x = posNow.x + this->diferencaInput[i].x;
        posInputNow[i].y = posNow.y + this->diferencaInput[i].y;
    
        this->inputs[i].setPos(posInputNow[i].x, posInputNow[i].y);
    
    }
    
    
    for(i = 0; i < this->nScrollBars; i++){
        posScrollNow[i].x = posNow.x + this->diferencaScroll[i].x;
        posScrollNow[i].y = posNow.y + this->diferencaScroll[i].y;
    
        this->scrollBars[i].setPos(posScrollNow[i].x, posScrollNow[i].y);
    
    }
    
    for(i = 0; i < this->nRectangles; i++){
        posRectangleNow[i].x = posNow.x + this->diferencaRectangle[i].x;
        posRectangleNow[i].y = posNow.y + this->diferencaRectangle[i].y;
    
        this->rectangles[i].setPosition(posRectangleNow[i]);
    
    }
    
    for(i = 0; i < this->nImages; i++){
        posImageNow[i].x = posNow.x + this->diferencaImage[i].x;
        posImageNow[i].y = posNow.y + this->diferencaImage[i].y;
    
        this->images[i].setPos(posImageNow[i]);
    
    }
    
    for(i = 0; i < this->ntexts; i++){
        posText1Now[i].x = posNow.x + this->diferencatext[i].x;
        posText1Now[i].y = posNow.y + this->diferencatext[i].y;
    
        this->texts[i].setPos(posText1Now[i]);
    
    }
    
    this->retangulo.setPosition(posNow);
    this->retangulo1.setPosition(posNow);
    this->retangulo2.setPosition(posNow.x, posNow.y + (this->height/2) );
    
    this->posX = posNow.x;
    this->posY = posNow.y;
}


bool board::getMouseClicou(){
    return this->mouseClicou;
}

int board::getId(){
    return this->id;
}

void board::setCanMove(bool canMove){
    this->canMove = canMove;
}

void board::setFirst(bool first){
    this->first = first;
}

bool board::getClose(){
    return this->close;
}

void board::setClose(bool close){
    this->close = close;
    
}

void sortBoard(board *boards, int number, sf::RenderWindow *window, LAYER *layer, int *mouse, MOUSE *mouses, KEYBOARD *keyboard){
    int i = 0;
    static board ptr(55, 0, 0, 0, 0, sf::Color(106, 90, 205, 255), sf::Color(0, 0, 128, 255), sf::Color( 0, 0, 205, 255), sf::Color( 0, 0, 205, 100), false, false, 0, 0, 0, 0, 0, 0); ;
    
// after, it does actions
    ptr.actionBoard(window, layer, mouse, mouses, keyboard);
    
    for(i = number - 1; i >= 0; i--){
        boards[i].actionBoard(window, layer, mouse, mouses, keyboard);
    }
    
    
// first, show the boards
    for(i = number - 1; i >= 0; i--){
        if ( (boards[i].getMouseClicou()) && (!ptr.colisionBoard(window, layer, mouse)) ){
            ptr = boards[i];
            ptr.setFirst(true);
        } 
        else {
            boards[i].setFirst(false);
            boards[i].showBoard(window, layer, mouse);
        }
        
    }


ptr.showBoard(window, layer, mouse);
    
    
// check if window close and if ptr and board equal.
    for(i = 0; i < number; i++){
        if (boards[i].getId() == ptr.getId())
            if ( boards[i].getClose() ){
                ptr.setClose(true);
            } else if ( ptr.getClose() ){
                boards[i].setClose(true);
            } else
                boards[i] = ptr;
    }
    
}

void board::setText(TEXTING text, int pos, bool order){
    this->texts[pos] = text;
    if(order)
        this->texts[pos].sortText(this->texts[pos].getString());
    
    sf::Vector2f posBoard = this->retangulo.getPosition();
    sf::Vector2f posText = this->texts[pos].text.getPosition();
    
    this->diferencatext[pos].x = posText.x - posBoard.x;
    this->diferencatext[pos].y = posText.y - posBoard.y;
    
}

void board::setImage(IMAGE image, int pos){
    this->images[pos] = image;
    
    sf::Vector2f posBoard = this->retangulo.getPosition();
    sf::Vector2f posImage = this->images[pos].image.getPosition();
    
    this->diferencaImage[pos].x = posImage.x - posBoard.x;
    this->diferencaImage[pos].y = posImage.y - posBoard.y;
}

void board::setRectangle(sf::RectangleShape rectangle, int pos){
    this->rectangles[pos] = rectangle;
    
    sf::Vector2f posBoard = this->retangulo.getPosition();
    sf::Vector2f posRectangle = this->rectangles[pos].getPosition();
    
    this->diferencaRectangle[pos].x = posRectangle.x - posBoard.x;
    this->diferencaRectangle[pos].y = posRectangle.y - posBoard.y;
}

void board::setScrollBar(SCROLLBAR scrollbar, int pos){
    this->scrollBars[pos] = scrollbar;
    
    sf::Vector2f posBoard = this->retangulo.getPosition();
    
    this->diferencaScroll[pos].x = this->scrollBars[pos].x - posBoard.x;
    this->diferencaScroll[pos].y = this->scrollBars[pos].y - posBoard.y;
}

void board::setInput(INPUT input, int pos){
    this->inputs[pos] = input;
    
    sf::Vector2f posBoard = this->retangulo.getPosition();
    
    this->diferencaInput[pos].x = this->inputs[pos].x - posBoard.x;
    this->diferencaInput[pos].y = this->inputs[pos].y - posBoard.y;
    
}

void board::setButtonHandle(BUTTONHANDLE button, int pos){
    
    this->buttonsHandle[pos] = button;
    
    sf::Vector2f posBoard = this->retangulo.getPosition();
    
    this->buttonsHandle[pos].diferencaBoard.x = this->buttonsHandle[pos].x - posBoard.x;
    this->buttonsHandle[pos].diferencaBoard.y = this->buttonsHandle[pos].y - posBoard.y;
    
    this->buttonsHandle[pos].diferencaMinMax[0] = this->buttonsHandle[pos].posMinY - posBoard.y;
    this->buttonsHandle[pos].diferencaMinMax[1] = this->buttonsHandle[pos].posMaxY - posBoard.y;
    this->buttonsHandle[pos].diferencaMinMax[2] = this->buttonsHandle[pos].posMinX - posBoard.x;
    this->buttonsHandle[pos].diferencaMinMax[3] = this->buttonsHandle[pos].posMaxX - posBoard.x;
}