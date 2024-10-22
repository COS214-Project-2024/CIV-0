#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"

class House : public ResidentialBuilding
{
public:
    House();
    House(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~House();

    Entity* clone();
};

#endif // HOUSE_H
