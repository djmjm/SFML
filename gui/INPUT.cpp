#include "INPUT.h"

INPUT::INPUT()
{
}


INPUT::INPUT(int x, int y, int xSize, int ySize, int length, sf::Color color1, sf::Color colorBound){
    
    this->length = length;
    
    this->string = new char[256];
    this->aux = new char[256];
    
    strcpy(this->string, "                       ");
    strcpy(this->aux, "                       ");
    
    this->stringLenght = -1;
    
    this->x = x;
    this->y = y;
    
    this->color1 = color1;
    this->colorBound = colorBound;
    
    this->rectangle.setFillColor(this->color1);
    this->rectangle.setOutlineThickness(0.5);
    this->rectangle.setOutlineColor(this->colorBound);
    this->rectangle.setPosition(this->x, this->y);
    this->rectangle.setSize(sf::Vector2f(xSize, ySize) );
    
    this->xSize = xSize;
    this->ySize = ySize;
    
    this->font.loadFromFile("fonts/fontError.ttf");
    
    this->text.setColor(sf::Color::Black);
    this->text.setFont(this->font);
    this->text.setPosition(x + 5, y + 5);
    this->text.setCharacterSize(12);
    
}

INPUT::~INPUT()
{
}


void INPUT::showInput(sf::RenderWindow *window){
    
    window->draw(this->rectangle);
    window->draw(this->text);
    
}

void INPUT::setPos(int x, int y){
    
    this->x = x;
    this->y = y;
    this->rectangle.setPosition(x, y);
    this->text.setPosition(x + 5, y + 5);
    
}

bool INPUT::colision(sf::RenderWindow *window, MOUSE *mouses, LAYER *layer){
    
    sf::Vector2f  posMouse = mouses->mouse.getPosition();
    
    if( (posMouse.x > this->x) && (posMouse.x < this->x + this->xSize) && (posMouse.y > this->y) && (posMouse.y < this->y + this->ySize) ){
        mouses->setTexture(1);
        layer->setLayer(2);
        return true;
    } else {
        return false;
    }
    
    
}

void INPUT::action(sf::RenderWindow *window, MOUSE *mouses, LAYER *layer, int *mouse, KEYBOARD *keyboard){
    
    if( (this->colision(window, mouses, layer)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))  && (*mouse == 0)){
        this->active = true;
        *mouse = 1;
    }
        
    if((this->active) ){
        
        char aux = this->presKey(keyboard);
        
        if (this->stringLenght < this->length) {
                
            if( (aux != '0') && (aux != '1')){
            
                this->string[this->stringLenght+1] = aux;
                this->stringLenght++;
                this->string[this->stringLenght+1] = '\0';
                this->text.setString(this->string);
            
            } else if (aux == '1'){
                this->string[this->stringLenght] = '\0';
                this->text.setString(this->string);
                if(this->stringLenght >= 0)
                this->stringLenght--;
            }
        
            if(this->string[this->stringLenght + 1] == '|'){
                this->string[this->stringLenght + 1] = '\0';
            } else {
                this->string[this->stringLenght + 1] = '|';
                this->string[this->stringLenght + 2] = '\0';
            }
        
            this->text.setString(this->string);
        } else {
            if( (aux != '0') && (aux != '1')){
            
                this->string[this->stringLenght+1] = aux;
                this->stringLenght++;
                this->string[this->stringLenght+1] = '\0';
                
                this->equalString();
                
                this->text.setString(this->aux);
            
            } else if (aux == '1'){
                this->string[this->stringLenght] = '\0';
                this->text.setString(this->string);
                if(this->stringLenght >= 0)
                this->stringLenght--;
                
                this->equalString();
                
                this->text.setString(this->aux);
            }
        
            if(this->aux[this->length + 1] == '|'){
                this->aux[this->length + 1] = '\0';
            } else {
                this->aux[this->length + 1] = '|';
                this->aux[this->length + 2] = '\0';
            }
        
            this->text.setString(this->aux);
        }
    }
    
    if( (!this->colision(window, mouses, layer)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (*mouse == 0) ){
        this->active = false;
        this->string[this->stringLenght + 1] = '\0';
        
        if (this->stringLenght < this->length) 
            this->text.setString(this->string);
        else this->text.setString(this->aux);
                
    }
    
}

char INPUT::presKey(KEYBOARD *keyboard){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (!keyboard->activeW) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  ){
        keyboard->activeW = true;
        return 'W';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && (!keyboard->activeE) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeE = true;
        return 'E';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (!keyboard->activeR) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeR = true;
        return 'R';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T) && (!keyboard->activeT) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeT = true;
        return 'T';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && (!keyboard->activeY) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeY = true;
        return 'Y';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U) && (!keyboard->activeU) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeU = true;
        return 'U';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && (!keyboard->activeI) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeI = true;
        return 'I';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::O) && (!keyboard->activeO) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeO = true;
        return 'O';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) && (!keyboard->activeP) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeP = true;
        return 'P';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (!keyboard->activeA) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeA = true;
        return 'A';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (!keyboard->activeS) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeS = true;
        return 'S';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (!keyboard->activeD) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeD = true;
        return 'D';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && (!keyboard->activeF) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeF = true;
        return 'F';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G) && (!keyboard->activeG) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeG = true;
        return 'G';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H) && (!keyboard->activeH) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeH = true;
        return 'H';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J) && (!keyboard->activeJ) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeJ = true;
        return 'J';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K) && (!keyboard->activeK) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeK = true;
        return 'K';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) && (!keyboard->activeL) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeL = true;
        return 'L';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (!keyboard->activeZ) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeZ = true;
        return 'Z';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (!keyboard->activeX) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeX = true;
        return 'X';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && (!keyboard->activeC) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeC = true;
        return 'C';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::V) && (!keyboard->activeV) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeV = true;
        return 'V';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B) && (!keyboard->activeB) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeB = true;
        return 'B';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N) && (!keyboard->activeN) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeN = true;
        return 'N';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M) && (!keyboard->activeM) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeM = true;
        return 'M';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && (!keyboard->activeQ) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ){
        keyboard->activeQ = true;
        return 'Q';
    } else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) && (!keyboard->activeQ)  ){
        keyboard->activeQ = true;
        return 'q';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (!keyboard->activeW)  ){
        keyboard->activeW = true;
        return 'w';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && (!keyboard->activeE) ){
        keyboard->activeE = true;
        return 'e';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (!keyboard->activeR) ){
        keyboard->activeR = true;
        return 'r';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T) && (!keyboard->activeT) ){
        keyboard->activeT = true;
        return 't';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && (!keyboard->activeY) ){
        keyboard->activeY = true;
        return 'y';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U) && (!keyboard->activeU) ){
        keyboard->activeU = true;
        return 'u';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && (!keyboard->activeI) ){
        keyboard->activeI = true;
        return 'i';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::O) && (!keyboard->activeO) ){
        keyboard->activeO = true;
        return 'o';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) && (!keyboard->activeP) ){
        keyboard->activeP = true;
        return 'p';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (!keyboard->activeA) ){
        keyboard->activeA = true;
        return 'a';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (!keyboard->activeS) ){
        keyboard->activeS = true;
        return 's';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (!keyboard->activeD) ){
        keyboard->activeD = true;
        return 'd';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && (!keyboard->activeF) ){
        keyboard->activeF = true;
        return 'f';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G) && (!keyboard->activeG) ){
        keyboard->activeG = true;
        return 'g';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H) && (!keyboard->activeH) ){
        keyboard->activeH = true;
        return 'h';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J) && (!keyboard->activeJ) ){
        keyboard->activeJ = true;
        return 'j';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K) && (!keyboard->activeK) ){
        keyboard->activeK = true;
        return 'k';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) && (!keyboard->activeL) ){
        keyboard->activeL = true;
        return 'l';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (!keyboard->activeZ) ){
        keyboard->activeZ = true;
        return 'z';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (!keyboard->activeX) ){
        keyboard->activeX = true;
        return 'x';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && (!keyboard->activeC) ){
        keyboard->activeC = true;
        return 'c';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::V) && (!keyboard->activeV) ){
        keyboard->activeV = true;
        return 'v';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B) && (!keyboard->activeB) ){
        keyboard->activeB = true;
        return 'b';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N) && (!keyboard->activeN) ){
        keyboard->activeN = true;
        return 'n';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M) && (!keyboard->activeM) ){
        keyboard->activeM = true;
        return 'm';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (!keyboard->activeSpace) ){
        keyboard->activeSpace = true;
        return ' ';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && (!keyboard->activeBackspace) ){
        keyboard->activeBackspace = true;
        return '1';
    } else return '0';
}

void INPUT::equalString(){
    
    int diff = this->stringLenght - this->length;
    
    int i = diff, j = 0;
    
    for(i = diff; this->string[i] != '\0'; i++){
        
        this->aux[j] = this->string[i];

        j++;
    }
    aux[j] = '\0';
    
}