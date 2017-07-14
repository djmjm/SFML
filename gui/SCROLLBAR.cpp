#include "SCROLLBAR.h"

SCROLLBAR::SCROLLBAR(int x, int y, int nTexts, int mTexts, int nStrings)
{
    
    this->idChoose = -1;
    this->texts = new TEXTING*[mTexts];
    
    int i = 0, j = 0;
    
    for(i = 0; i < nTexts; i++){
        
        this->texts[i] = new TEXTING[nTexts];
        
    }
    
    this->diferencaAmongTexts = new sf::Vector2f*[mTexts];
    
    for(i = 0; i < nTexts; i++){
        
        this->diferencaAmongTexts[i] = new sf::Vector2f[nTexts];
        
    }
    
    this->strings = new char**[50];
    
    for(i = 0; i < 50; i++){
        
        this->strings[i] = new char*[800];
        
        for(j = 0; j < 800; j++){
            
            this->strings[i][j] = new char [256];
            
        }
        
    }
    
    this->id = new int[nTexts];
    
    this->nTexts = nTexts;
    this->mTexts = mTexts;
    this->nStrings = nStrings;
    
    this->down = new BUTTON(x, y + 100, 15, 15, "images/scrollButon1.png", "images/scrollButon12.png");
    this->up = new BUTTON(x, y, 15, 15, "images/scrollButon2.png", "images/scrollButon22.png");
    this->midle = new BUTTONHANDLE(x, y + 50, 0, y + 10, 0, y + 90, 15, 15, "images/midlebuttonScroll.png", 3);
    
    this->midle->diferencaMaxY = this->midle->posMaxY - y;
    this->midle->diferencaMinY = this->midle->posMinY - y;
    
    this->x = x;
    this->y = y;
    
}

SCROLLBAR::SCROLLBAR(){
    
}

SCROLLBAR::~SCROLLBAR()
{
}

void SCROLLBAR::showScroll(sf::RenderWindow *window, LAYER *layer, int *mouse){
    
    this->compareTextsAndStrings();
    
    int i = 0, k = 0;
    
    
    for(k = 0; k < this->mTexts; k++){
        for(i = 0; i < this->nTexts; i++){
        
            this->texts[k][i].showText(window);
        
        }
        
    }
     
      
     
     
    
    this->midle->showButton(window);
    this->up->showButton(window, layer, mouse);
    this->down->showButton(window, layer, mouse);
}

void SCROLLBAR::setPos(int x, int y){
    //setting texts
    
    
    int i = 0, k = 0;
    
    
    for(k = 0; k < this->mTexts; k++){
        for(i = 0; i < this->nTexts; i++){
            
            this->texts[k][i].setPos(sf::Vector2f(this->diferencaAmongTexts[k][i].x + x, this->diferencaAmongTexts[k][i].y + y));
        
        }
    }
    
    

      
    //setting buttons
    int diferencaMidle = midle->returnY() - this->y;
    
    this->up->changePos(x + this->up->width, y + this->up->height);
    
    this->down->changePos(x + this->down->width, y + 100 + this->down->height);
    
    this->midle->setPos(x, y + diferencaMidle);
    this->midle->posMaxY = this->midle->diferencaMaxY + y;
    this->midle->posMinY = this->midle->diferencaMinY + y;
    
    this->x = x;
    this->y = y;
    
}

void SCROLLBAR::action(sf::RenderWindow *window, LAYER *layer, MOUSE *mouses, int *mouse){
    
    // run text's actions
    
    int i = 0, k = 0;
    
    
    for(k = 0; k < this->mTexts; k++){
        for(i = 0; i < this->nTexts; i++){
            
            if(*mouse == 0)
                this->texts[k][i].textActivate = this->texts[k][i].colisionText(window, mouses, layer);
            
            this->texts[k][i].colisionText(window, mouses, layer);
            this->texts[k][i].actionText(mouses, mouse);
            
            if( (this->texts[k][i].returnType() == 2)  && (this->texts[k][i].returnClicou())  ){
                this->texts[k][i].setClicou(false);
                this->idChoose = this->id[this->scroolPos + i];
                
            }
        
        }
    }
    
    this->balanceChoose();
    
     
    // run actions on the midle button
    
    if(this->up->colision(window) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (this->midle->returnY() > this->midle->posMinY) && (*mouse == 0) ){
        this->midle->setPos(this->midle->returnX(), this->midle->returnY() - this->diferencatexts);
        *mouse = 1;
    }
    
    if(this->down->colision(window) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (this->midle->returnY() < this->midle->posMaxY) && (*mouse == 0) ){
        this->midle->setPos(this->midle->returnX(), this->midle->returnY() + this->diferencatexts);
        *mouse = 1;
    }
    
    // run button's action;
    
    this->up->buttonAction(window, layer, mouse, mouses);
    this->down->buttonAction(window, layer, mouse, mouses);
    
    this->down->buttonClick();
    
    this->midle->action(window, layer, mouse, mouses);
    
}

void SCROLLBAR::setString(char *string, int pos, int m){
    
    strcpy(this->strings[m][pos], string);
    
    if(this->nTexts > pos){
        this->texts[m][pos].text.setString(this->strings[m][pos]);
    }
    
}

void SCROLLBAR::setId(int id, int pos, int m){
    
    this->id[pos] = id;
    
    /*
    if(this->nTexts > pos){
        this->texts[m][pos].setId(id);
    }
    
     * */
}

void SCROLLBAR::setTexts(int x, int y, int differenceY, int differenceX, int type, int width, int charSize, sf::Color color1, sf::Color color2, sf::Color backSelect){
    
    int i = 0, k = 0, addX = 0, addY = 0;
    
    for(k = 0; k < this->mTexts; k++){
        for(i = 0; i < this->nTexts; i++){
        
            this->texts[k][i].setText(x + addX, y + addY, this->strings[k][i], "fonts/textDescription.ttf",  charSize, width, color1, color2, backSelect, type );
            this->texts[k][i].setId(this->id[i]);
        
            this->diferencaAmongTexts[k][i].x = (x + addX) - this->x;
            this->diferencaAmongTexts[k][i].y = (y + addY) - this->y;
        
            addY += differenceY;
        
        }
        
        addY = 0;
    
        addX += differenceX;
    
    }
    
    
}

void SCROLLBAR::compareTextsAndStrings(){
    if (this->nTexts < this->nStrings){
        double dif = this->nStrings;
        this->diferencatexts = ( (this->midle->posMaxY - this->midle->posMinY) / dif);
        
        
        int i = 1;
        int k = 0;
        int j = 0;
        
        while(i){
            if(this->midle->returnY() > ( (j+1) * this->diferencatexts) + this->midle->posMinY){
                if( j + this->nTexts < this->nStrings)
                    j++;
                else i = 0;
            } else (i = 0);
        }
        
        this->scroolPos = j;
        for(k = 0; k < this->mTexts; k++) {
            for(i = 0; i < this->nTexts; i++){
                this->texts[k][i].text.setString(this->strings[k][j]);
                this->texts[k][i].setId(this->id[j]);
                j++;
            }
        j = this->scroolPos;
        }
    }
}

void SCROLLBAR::setnStrings(int n){
    
    this->nStrings = n;
    
}

int SCROLLBAR::getnStrings(){
    
    return this->nStrings;
    
}

void SCROLLBAR::balanceChoose(){
    
    int i = 0;
    
    int j = this->scroolPos;
    
    for(i = 0; i < this->nTexts; i++){
        
        if(this->idChoose != this->id[j]){
            
            this->texts[0][i].setChoose(false);
            
        } else{
            
            this->texts[0][i].setChoose(true);
            
        }
        
        j++;
    }
    
}

