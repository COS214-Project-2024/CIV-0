#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "entities/utility/base/Utility.h"

class PowerPlant : public Utility
{
public:
    PowerPlant();
    PowerPlant(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~PowerPlant();

    void update();
    Entity* clone();
};

#endif // POWERPLANT_H
