#ifndef LAYER_H
#define LAYER_H

// defines which layer the mouse is on.

class LAYER
{
public:
    LAYER();
    ~LAYER();
    void setLayer(int layer);
    int getLayer();
    
protected:
    int layer;

};

#endif // LAYER_H
