#ifndef SERVICEBUILDING_H
#define SERVICEBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/building/residential/ResidentialBuilding.h"
#include "entities/base/Subject.h"

class ServiceBuilding : public Building, public Subject
{
public:
    ServiceBuilding();
    ServiceBuilding(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~ServiceBuilding();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // SERVICEBUILDING_H
