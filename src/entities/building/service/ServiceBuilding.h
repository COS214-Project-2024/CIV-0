#ifndef SERVICEBUILDING_H
#define SERVICEBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"

class ServiceBuilding : public Building, public Subject
{
public:
    ServiceBuilding();
    ServiceBuilding(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~ServiceBuilding();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // SERVICEBUILDING_H
