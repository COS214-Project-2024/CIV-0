#ifndef ECONOMICBUILDING_H
#define ECONOMICBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"

class EconomicBuilding : public Building, public Subject
{
public:
    EconomicBuilding();
    EconomicBuilding(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~EconomicBuilding();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // ECONOMICBUILDING_H
