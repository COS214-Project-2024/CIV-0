#ifndef AMENITY_H
#define AMENITY_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"

class Amenity : public Building, public Subject
{
public:
    Amenity();
    Amenity(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Amenity();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // AMENITY_H
