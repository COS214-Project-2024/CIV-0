#ifndef AMENITYFACTORY_H
#define AMENITYFACTORY_H

#include "factory/base/EntityFactory.h"

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