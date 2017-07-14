#include "LAYER.h"

// defines which layer the mouse is on.

LAYER::LAYER()
{
    this->layer = 0;
}

LAYER::~LAYER()
{
}

int LAYER::getLayer(){
    return this->layer;
}

void LAYER::setLayer(int layer){
    this->layer = layer;
}

