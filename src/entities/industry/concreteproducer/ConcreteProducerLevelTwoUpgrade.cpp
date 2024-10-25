#include "ConcreteProducerLevelTwoUpgrade.h"

ConcreteProducerLevelTwoUpgrade::ConcreteProducerLevelTwoUpgrade(ConcreteProducer* concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelTwoUpgrade::ConcreteProducerLevelTwoUpgrade(ConcreteProducerLevelTwoUpgrade* concreteProd) : ConcreteProducerUpgrade(concreteProd){}
ConcreteProducerLevelTwoUpgrade::~ConcreteProducerLevelTwoUpgrade() {}

void ConcreteProducerLevelTwoUpgrade::update() {
    concreteProducer->update();
}

int ConcreteProducerLevelTwoUpgrade::getOutput() {
    concreteProducer->getOutput() * UPGRADE;
}

Entity* ConcreteProducerLevelTwoUpgrade::clone() {
    return new ConcreteProducerLevelTwoUpgrade(this);
}