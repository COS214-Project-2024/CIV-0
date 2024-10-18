#ifndef MONUMENT_H
#define MONUMENT_H

#include "Amenity.h"

class Monument : public Amenity
{
public:
    Monument();
    Monument(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Monument();

    void update();
    Entity* clone();
};

#endif // MONUMENT_H
