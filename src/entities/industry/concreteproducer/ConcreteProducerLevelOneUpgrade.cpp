#include "ConcreteProducerLevelOneUpgrade.h"

ConcreteProducerLevelOneUpgrade::ConcreteProducerLevelOneUpgrade(ConcreteProducer* concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelOneUpgrade::ConcreteProducerLevelOneUpgrade(ConcreteProducerLevelOneUpgrade* concreteProd) : ConcreteProducerUpgrade(concreteProd){}
ConcreteProducerLevelOneUpgrade::~ConcreteProducerLevelOneUpgrade() {}


void ConcreteProducerLevelOneUpgrade::update() {
    concreteProducer->update();
}

Entity* ConcreteProducerLevelOneUpgrade::clone() {
    return new ConcreteProducerLevelOneUpgrade(this);
}

int ConcreteProducerLevelOneUpgrade::getOutput() {
    return concreteProducer->getOutput() * UPGRADE;
}