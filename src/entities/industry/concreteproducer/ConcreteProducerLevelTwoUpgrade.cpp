
#include "ConcreteProducerLevelTwoUpgrade.h"
#include "entities/industry/concreteproducer/ConcreteProducerLevelThreeUpgrade.h"

ConcreteProducerLevelTwoUpgrade::ConcreteProducerLevelTwoUpgrade(ConcreteProducer *concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelTwoUpgrade::ConcreteProducerLevelTwoUpgrade(ConcreteProducerLevelTwoUpgrade *concreteProd) : ConcreteProducerUpgrade(concreteProd) {}
ConcreteProducerLevelTwoUpgrade::~ConcreteProducerLevelTwoUpgrade() {}

void ConcreteProducerLevelTwoUpgrade::update()
{
    concreteProducer->update();
}

int ConcreteProducerLevelTwoUpgrade::getLevel()
{
    return 2;
}

int ConcreteProducerLevelTwoUpgrade::getOutput()
{
    return concreteProducer->getOutput() * UPGRADE;
}

Entity *ConcreteProducerLevelTwoUpgrade::clone()
{
    return new ConcreteProducerLevelTwoUpgrade(this);
}

Entity* ConcreteProducerLevelTwoUpgrade::upgrade() {
    return new ConcreteProducerLevelThreeUpgrade(concreteProducer);
}

Cost ConcreteProducerLevelTwoUpgrade::getCost()
{
    return Cost(concreteProducer->getCost().moneyCost * UPGRADE, concreteProducer->getCost().woodCost * UPGRADE, concreteProducer->getCost().stoneCost * UPGRADE, concreteProducer->getCost().concreteCost * UPGRADE);
}