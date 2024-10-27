#include "ConcreteProducerUpgrade.h"

ConcreteProducerUpgrade::ConcreteProducerUpgrade(ConcreteProducer* concreteProd) {
    this->concreteProducer = concreteProd;
}

ConcreteProducerUpgrade::ConcreteProducerUpgrade(ConcreteProducerUpgrade* concreteProd) : ConcreteProducer(concreteProd) {
    this->concreteProducer = concreteProd->concreteProducer;
}

ConcreteProducerUpgrade::~ConcreteProducerUpgrade() {}
