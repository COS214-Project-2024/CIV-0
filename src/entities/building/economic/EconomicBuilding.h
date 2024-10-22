#ifndef ECONOMICBUILDING_H
#define ECONOMICBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"
#include "entities/building/residential/ResidentialBuilding.h"

class EconomicBuilding : public Building, public Subject
{
public:
    EconomicBuilding();
    EconomicBuilding(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~EconomicBuilding();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // ECONOMICBUILDING_H
