#ifndef THEATER_H
#define THEATER_H

#include "Amenity.h"

class Theater : public Amenity
{
public:
    Theater();
    Theater(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Theater();

    void update();
    Entity* clone();
};

#endif // THEATER_H
