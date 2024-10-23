#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H
#include "Entity.h"
#include "EntityType.h"
class EntityFactory
{
public:
    EntityFactory();
    ~EntityFactory();
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos) = 0;
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos) = 0;
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos) = 0;
};

#endif
