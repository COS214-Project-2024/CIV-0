
#include "ConcreteProducerLevelThreeUpgrade.h"

ConcreteProducerLevelThreeUpgrade::ConcreteProducerLevelThreeUpgrade(ConcreteProducer *concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelThreeUpgrade::ConcreteProducerLevelThreeUpgrade(ConcreteProducerLevelThreeUpgrade *concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelThreeUpgrade::~ConcreteProducerLevelThreeUpgrade() {}

void ConcreteProducerLevelThreeUpgrade::update()
{
    concreteProducer->update();
}

int ConcreteProducerLevelThreeUpgrade::getLevel()
{
    return 3;
}

int ConcreteProducerLevelThreeUpgrade::getOutput()
{
    return concreteProducer->getOutput() * UPGRADE;
}

Entity *ConcreteProducerLevelThreeUpgrade::clone()
{
    return new ConcreteProducerLevelThreeUpgrade(this);
}

Cost ConcreteProducerLevelThreeUpgrade::getCost()
{
    return Cost(concreteProducer->getCost().moneyCost * UPGRADE, concreteProducer->getCost().woodCost * UPGRADE, concreteProducer->getCost().stoneCost * UPGRADE, concreteProducer->getCost().concreteCost * UPGRADE);
}

Entity* ConcreteProducerLevelThreeUpgrade::upgrade() {
    return nullptr;
}
