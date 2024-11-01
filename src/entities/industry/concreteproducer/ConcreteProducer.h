#ifndef CONCRETEPRODUCER_H
#define CONCRETEPRODUCER_H

#include "entities/industry/base/Industry.h"

class ConcreteProducer : public Industry
{
public:
    ConcreteProducer();
    ConcreteProducer(EntityConfig ec, Size size, int xPos, int yPos);
    ConcreteProducer(ConcreteProducer *concreteProducer);
    virtual ~ConcreteProducer();
    void update();
    Entity *clone();
    Cost getCost();
};

#endif // CONCRETEPRODUCER_H
