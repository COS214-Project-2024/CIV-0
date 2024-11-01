#ifndef WOODPRODUCER_H
#define WOODPRODUCER_H

#include "entities/industry/base/Industry.h"

class WoodProducerLevelOneUpgrade;

class WoodProducer : public Industry
{
public:
    WoodProducer(EntityConfig ec, Size size, int xPos, int yPos);
    WoodProducer(WoodProducer *woodProducer);
    virtual ~WoodProducer();
    void update();
    Entity *clone();
    Entity* upgrade();
};

#endif // WOODPRODUCER_H
