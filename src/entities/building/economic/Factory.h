#ifndef FACTORY_H
#define FACTORY_H

#include "EconomicBuilding.h"

class Factory : public EconomicBuilding
{
public:
    Factory();
    Factory(EntityConfig ec, Size size, int xPos, int yPos);
    Factory(Factory* factory);
    ~Factory();

    void update();
    Entity* clone();
};

#endif // FACTORY_H
