#include "ConcreteProducerLevelOneUpgrade.h"
#include "entities/industry/concreteproducer/ConcreteProducerLevelTwoUpgrade.h"

ConcreteProducerLevelOneUpgrade::ConcreteProducerLevelOneUpgrade(ConcreteProducer *concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelOneUpgrade::ConcreteProducerLevelOneUpgrade(ConcreteProducerLevelOneUpgrade *concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelOneUpgrade::~ConcreteProducerLevelOneUpgrade() {}

void ConcreteProducerLevelOneUpgrade::update()
{
    concreteProducer->update();
}

int ConcreteProducerLevelOneUpgrade::getLevel()
{
    return 1;
}

Entity *ConcreteProducerLevelOneUpgrade::clone()
{
    return new ConcreteProducerLevelOneUpgrade(this);
}

int ConcreteProducerLevelOneUpgrade::getOutput()
{
    return concreteProducer->getOutput() * UPGRADE;
}

Entity* ConcreteProducerLevelOneUpgrade::upgrade() {
    return new ConcreteProducerLevelTwoUpgrade(concreteProducer);
}

Cost ConcreteProducerLevelOneUpgrade::getCost() {
    return Cost(concreteProducer->getCost().moneyCost * UPGRADE, concreteProducer->getCost().woodCost * UPGRADE, concreteProducer->getCost().stoneCost * UPGRADE, concreteProducer->getCost().concreteCost * UPGRADE);
}