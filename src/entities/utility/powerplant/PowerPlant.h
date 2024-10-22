#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "entities/utility/base/Utility.h"

class PowerPlant : public Utility
{
public:
    PowerPlant();
    PowerPlant(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~PowerPlant();

    void update();
    Entity* clone();
};

#endif // POWERPLANT_H
