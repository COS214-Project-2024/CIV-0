#ifndef BUILDING_H
#define BUILDING_H

#include "entities/base/Entity.h"

class Building : public Entity
{
public:
    Building();
    Building(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~Building();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // BUILDING_H
