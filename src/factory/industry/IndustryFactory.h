#ifndef INDUSTRYFACTORY_H
#define INDUSTRYFACTORY_H
#include "factory/base/EntityFactory.h"
#include "entities/industry/stoneproducer/StoneProducer.h"
#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/industry/woodproducer/WoodProducer.h"

class IndustryFactory : EntityFactory
{
public:
    IndustryFactory();
    ~IndustryFactory();
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);
    private:
        Entity* createConcreteProducer(Size size, int xPos, int yPos);
    Entity* createStoneProducer(Size size, int xPos, int yPos);
    Entity* createWoodProducer(Size size, int xPos, int yPos);
};

#endif // INDUSTRYFACTORY_H
