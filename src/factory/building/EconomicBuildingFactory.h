#ifndef ECONOMICBUILDINGFACTORY_H
#define ECONOMICBUILDINGFACTORY_H

#include "factory/base/EntityFactory.h"

class EconomicBuildingFactory : EntityFactory
{
public:
    EconomicBuildingFactory();
    ~EconomicBuildingFactory();
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);
    private:
    Entity* createFactory(Size size, int xPos, int yPos);
    Entity* createShoppingMall(Size size, int xPos, int yPos);
};

#endif