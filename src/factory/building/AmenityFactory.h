#ifndef AMENITYFACTORY_H
#define AMENITYFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/amenity/Park.h"
#include "entities/building/amenity/Theater.h"
#include "entities/building/amenity/Monument.h"
class AmenityFactory : public EntityFactory
{
public:
    AmenityFactory();
    ~AmenityFactory();
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);
    private:
    Entity* createPark(Size size, int xPos, int yPos);
    Entity* createTheater(Size size, int xPos, int yPos);
    Entity* createMonument(Size size, int xPos, int yPos);

};

#endif