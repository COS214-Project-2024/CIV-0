#ifndef CONCRETEPRODUCERUPGRADE_H
#define CONCRETEPRODUCERUPGRADE_H

#include "ConcreteProducer.h"
class ConcreteProducerUpgrade : public ConcreteProducer
{
public:
    ConcreteProducerUpgrade();
    ~ConcreteProducerUpgrade();

private:
    ConcreteProducer *concreteProducer;
};

#endif // CONCRETEPRODUCERUPGRADE_H
