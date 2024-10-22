#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "entities/utility/base/Utility.h"

class WaterSupply : Utility
{
public:
    WaterSupply();
    WaterSupply(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~WaterSupply();

    void update();
    Entity* clone();
};

#endif // WATERSUPPLY_H
