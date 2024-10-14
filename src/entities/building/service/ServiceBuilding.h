#ifndef SERVICEBUILDING_H
#define SERVICEBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"

class ServiceBuilding : public Building, public Subject
{
public:
    ServiceBuilding();
    ~ServiceBuilding();
};

#endif // SERVICEBUILDING_H
