#include "ConcreteProducerUpgrade.h"




ConcreteProducerUpgrade::ConcreteProducerUpgrade(ConcreteProducer *concreteProd) : ConcreteProducer(concreteProd)
{
    this->concreteProducer = new ConcreteProducer(concreteProd);
}

ConcreteProducerUpgrade::ConcreteProducerUpgrade(ConcreteProducerUpgrade *concreteProducerUpgrade) : ConcreteProducer(concreteProducerUpgrade)
{
    this->concreteProducer = new ConcreteProducer(concreteProducerUpgrade->concreteProducer);
}

ConcreteProducerUpgrade::~ConcreteProducerUpgrade()
{
    if (concreteProducer != nullptr)
    {
        delete concreteProducer;
        concreteProducer = nullptr;
    }
}