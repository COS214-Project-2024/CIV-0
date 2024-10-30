#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H
#include "utils/EntityType.h"
#include "utils/Size.h"
#include "entities/building/service/ServiceBuilding.h"
#include "factory/building/ServiceBuildingFactory.h"

class ServiceManager
{
public:
    ServiceManager();
    ~ServiceManager();

    ServiceBuilding* buildService(EntityType type, Size size, int xPos, int yPos);
};

#endif // AMENITYMANAGER_H
