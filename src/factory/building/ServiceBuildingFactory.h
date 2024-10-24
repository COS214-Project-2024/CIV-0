#ifndef SERVICEBUILDINGFACTORY_H
#define SERVICEBUILDINGFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/service/Hospital.h"
#include "entities/building/service/PoliceStation.h"
#include "entities/building/service/School.h"

class ServiceBuildingFactory : EntityFactory
{
public:
    ServiceBuildingFactory();
    ~ServiceBuildingFactory();
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);
    private:
    Entity* createHospital(Size size, int xPos, int yPos);
    Entity* createPoliceStation(Size size, int xPos, int yPos);
    Entity* createSchool(Size size, int xPos, int yPos);
};

#endif // SERVICEBUILDINGFACTORY_H