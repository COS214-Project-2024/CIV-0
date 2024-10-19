#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "entities/utility/base/Utility.h"

class WaterSupply : public Utility{
public:
    WaterSupply();
    WaterSupply(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~WaterSupply();

    void update();
    Entity* clone();
};

#endif // WATERSUPPLY_H
