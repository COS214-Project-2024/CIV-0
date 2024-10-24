#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "factory/base/EntityFactory.h"

class ResidentialBuildingFactory : EntityFactory
{
public:
    ResidentialBuildingFactory();
    ~ResidentialBuildingFactory();
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);
    private:
    Entity* createHouse(Size size, int xPos, int yPos);
    Entity* createApartment(Size size, int xPos, int yPos);
};

#endif