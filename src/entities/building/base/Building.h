#ifndef BUILDING_H
#define BUILDING_H

#include "entities/base/Entity.h"

class Building : public Entity
{
public:
    Building();
    Building(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Building();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // BUILDING_H
