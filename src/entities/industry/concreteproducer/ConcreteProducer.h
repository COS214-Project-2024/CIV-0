#ifndef CONCRETEPRODUCER_H
#define CONCRETEPRODUCER_H

#include "entities/industry/base/Industry.h"

class ConcreteProducerLevelOneUpgrade;

class ConcreteProducer : public Industry
{
public:
    ConcreteProducer();
    ConcreteProducer(EntityConfig ec, Size size, int xPos, int yPos);
    ConcreteProducer(ConcreteProducer *concreteProducer);
    virtual ~ConcreteProducer();
    void update() override;
    Entity *clone() override;
    Entity *upgrade() override;
};

#endif // CONCRETEPRODUCER_H
