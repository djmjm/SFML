#include "TEXTING.h"


TEXTING::TEXTING(){
    
    
    this->font1.loadFromFile("fonts/font3.ttf");
    this->text.setFont(this->font1);
}

TEXTING::TEXTING(int x, int y, char *string, char *font, int charSize, int width, sf::Color color1, sf::Color color2, sf::Color colorSelection, int type)
{
    
    this->choose = false;
    this->clicou = false;
    
    this->tSelection1 = new sf::Texture;
    this->tSelection2 = new sf::Texture;
    this->SSelection = new sf::Sprite;
    
    
    this->tSelection1->loadFromFile("images/djmsfootball/seleciona1.png");
    this->tSelection2->loadFromFile("images/djmsfootball/seleciona2.png");
    this->SSelection->setTexture(*this->tSelection1);
    this->SSelection->setPosition(x - 20, y + 2);
    
    this->type = type;
    
    this->selection.setFillColor(colorSelection);
    
    this->color1 = color1;
    this->color2 = color2;
    
    this->height = 1;
    this->width = width;
    
    this->posX = x;
    this->posY = y;
    
    strcpy(this->string, string);
    
    this->font1.loadFromFile(font);
    
    this->text.setColor(color1);
    this->text.setString(string);
    this->text.setFont(this->font1);
    this->text.setPosition(this->posX, this->posY);
    this->text.setCharacterSize(charSize);
}

TEXTING::~TEXTING()
{
}

void TEXTING::setText(int x, int y, char *string, char *font, int charSize, int width, sf::Color color1, sf::Color color2, sf::Color colorSelection, int type){
    this->type = type;
    
    this->choose = false;
    this->clicou = false;
    
    this->tSelection1 = new sf::Texture;
    this->tSelection2 = new sf::Texture;
    this->SSelection = new sf::Sprite;
    
    this->tSelection1->loadFromFile("images/djmsfootball/seleciona1.png");
    this->tSelection2->loadFromFile("images/djmsfootball/seleciona2.png");
    this->SSelection->setTexture(*this->tSelection1);
    this->SSelection->setPosition(x - 20, y + 2);
    
    this->selection.setFillColor(colorSelection);
    
    this->color1 = color1;
    this->color2 = color2;
    
    this->height = 1;
    this->width = width;
    
    this->posX = x;
    this->posY = y;
    
    strcpy(this->string, string);
    
    this->font1.loadFromFile(font);
    
    this->text.setColor(color1);
    this->text.setString(string);
    this->text.setFont(this->font1);
    this->text.setPosition(this->posX, this->posY);
    this->text.setCharacterSize(charSize);
}

void TEXTING::showText(sf::RenderWindow *window){
    
    window->draw(this->selection);
    window->draw(this->text);
    
    if(this->type == 2)
        window->draw(*this->SSelection);
    
}

void TEXTING::setWidth(int width){
    this->width = width;
}

void TEXTING::sortText(char *strin){
    
    
    char testando[10000];
    strcpy(testando, strin);
    int i = 0, j = 0, k = 0;
    char aux;
    char aux2;
    
    for(i = 0; testando[i] != '\0'; i++){
        if(j == this->width){
            j = 0;
            aux = testando[i];
            for(k = i; testando[k] != '\0'; k++){
                aux2 = testando[k+1];
                testando[k+1] = aux;
                aux = aux2;
            }
            testando[k] = '\0';
            testando[i] = '\n';
            this->height++;
        }
        j++;
    }
    
    this->text.setString(testando);
    
}

char *TEXTING::getString(){
    return this->string;
}

bool TEXTING::colisionText(sf::RenderWindow *window, MOUSE *mouses, LAYER *layer){
    sf::Vector2f  posMouse = mouses->mouse.getPosition();
    sf::Vector2f  posText = this->text.getPosition();
    
    if( (posMouse.x + 5 > posText.x) && (posMouse.x + 5 < posText.x + this->width * 6) && (posMouse.y > posText.y) && (posMouse.y < posText.y + this->height * 14) ){
        if(this->type == 0)
            mouses->setTexture(1);
        else if( (this->type == 1) || (this->type == 2) )
            mouses->setTexture(2);
        layer->setLayer(2);
        return true;
    } else {
        return false;
    }
    
}

void TEXTING::actionText(MOUSE *mouses, int *mouse){
    
    sf::Vector2f posMouse = mouses->mouse.getPosition();
    this->selection.setPosition(this->text.getPosition());
    
    sf::Vector2f posText = this->text.getPosition();
    
    posMouse.x = posMouse.x + 20 - posText.x;
    posMouse.y = posMouse.y + 20 - posText.y;
    
    if(this->type == 0){
        if ( (this->textActivate ) && (sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) ){
            this->text.setColor(this->color2);
            this->selection.setSize(posMouse);
            *mouse = 1;
        }
        else {
            this->text.setColor(this->color1);
            sf::Vector2f zero(0, 0);
            
        
            this->selection.setSize(zero);
        }
    } else if(this->type == 1){
        if(this->textActivate){
            this->text.setColor(this->color2);
        } else this->text.setColor(this->color1);
    } else if(this->type == 2){
        
        if( (this->textActivate) && (sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) ){
            this->choose = true;
            this->clicou = true;
            this->SSelection->setTexture(*this->tSelection2);
        } else if (!this->choose){
            this->SSelection->setTexture(*this->tSelection1);
        } else if (this->choose){
            this->SSelection->setTexture(*this->tSelection2);
        }
        
    }
}

void TEXTING::setPos(sf::Vector2f pos){
    
    this->text.setPosition(pos);
    this->SSelection->setPosition(pos.x - 20, pos.y + 3);
    
}

void TEXTING::setId(int id){
    this->id = id;
}

int TEXTING::returnId(){
    
    return this->id;
    
}

int TEXTING::returnType(){
    
    return this->type;
    
}

bool TEXTING::returnClicou(){
    
    return this->clicou;
    
}

void TEXTING::setClicou(bool clicou){
    
    this->clicou = clicou;
    
}

void TEXTING::setChoose(bool choose){
    
    this->choose = choose;
    
}