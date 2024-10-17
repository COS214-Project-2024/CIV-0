#ifndef FACTORY_H
#define FACTORY_H

#include "EconomicBuilding.h"

class Factory : public EconomicBuilding
{
public:
    Factory();
    Factory(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Factory();

    void update();
    Entity* clone();
};

#endif // FACTORY_H
