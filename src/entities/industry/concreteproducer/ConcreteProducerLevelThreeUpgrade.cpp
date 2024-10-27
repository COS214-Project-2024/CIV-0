
#include "ConcreteProducerLevelThreeUpgrade.h"

ConcreteProducerLevelThreeUpgrade::ConcreteProducerLevelThreeUpgrade(ConcreteProducer* concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelThreeUpgrade::ConcreteProducerLevelThreeUpgrade(ConcreteProducerLevelThreeUpgrade* concreteProd) : ConcreteProducerUpgrade(concreteProd){}
ConcreteProducerLevelThreeUpgrade::~ConcreteProducerLevelThreeUpgrade() {}

void ConcreteProducerLevelThreeUpgrade::update() {
    concreteProducer->update();
}

int ConcreteProducerLevelThreeUpgrade::getOutput() {
    return concreteProducer->getOutput() * UPGRADE;
}

Entity* ConcreteProducerLevelThreeUpgrade::clone() {
    return new ConcreteProducerLevelThreeUpgrade(this);
}
