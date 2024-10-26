#ifndef CONCRETEPRODUCERUPGRADE_H
#define CONCRETEPRODUCERUPGRADE_H

#include "ConcreteProducer.h"
class ConcreteProducerUpgrade : public ConcreteProducer
{
public:
    ConcreteProducerUpgrade(ConcreteProducer* concreteProd);
    ConcreteProducerUpgrade(ConcreteProducerUpgrade* concreteProd);
    ~ConcreteProducerUpgrade();
    virtual int getOutput() = 0;
    virtual Entity* clone() = 0;
    virtual void update() = 0;

protected:
    ConcreteProducer *concreteProducer;
};

#endif // CONCRETEPRODUCERUPGRADE_H
