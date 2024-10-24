#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/base/Entity.h"
class UtilityFactory : EntityFactory {
   public:
    UtilityFactory();
    ~UtilityFactory();
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);

   private:
    Entity* createPowerPlant(Size size, int xPos, int yPos);
    Entity* createWaterSupply(Size size, int xPos, int yPos);
    Entity* createWasteManagement(Size size, int xPos, int yPos);
    Entity* createSewageSystem(Size size, int xPos, int yPos);
    Entity* createConcreteProducer(Size size, int xPos, int yPos);
    Entity* createStoneProducer(Size size, int xPos, int yPos);
    Entity* createWoodProducer(Size size, int xPos, int yPos);
};

#endif