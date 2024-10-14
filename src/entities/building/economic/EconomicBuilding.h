#ifndef ECONOMICBUILDING_H
#define ECONOMICBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"

class EconomicBuilding : public Building, public Subject
{
public:
    EconomicBuilding();
    ~EconomicBuilding();
};

#endif // ECONOMICBUILDING_H
