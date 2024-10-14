#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Observer.h"

class ResidentialBuilding : public Building, public Observer
{
public:
    ResidentialBuilding();
    ~ResidentialBuilding();
};

#endif // RESIDENTIALBUILDING_H
