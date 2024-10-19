#ifndef CONCRETEPRODUCERUPGRADE_H
#define CONCRETEPRODUCERUPGRADE_H

#include "ConcreteProducer.h"
#include "Entity.h"
class ConcreteProducerUpgrade : public ConcreteProducer
{
public:

    ConcreteProducerUpgrade();
    ~ConcreteProducerUpgrade();
    virtual Entity* clone() = 0;
    virtual void update() = 0;

private: 
    ConcreteProducer* concreteProducer;
};

#endif // CONCRETEPRODUCERUPGRADE_H
