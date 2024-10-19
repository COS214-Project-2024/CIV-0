#ifndef PARK_H
#define PARK_H

#include "Amenity.h"

class Park : public Amenity
{
public:
    Park();
    Park(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Park();

    void update();
    Entity* clone();
};

#endif // PARK_H
