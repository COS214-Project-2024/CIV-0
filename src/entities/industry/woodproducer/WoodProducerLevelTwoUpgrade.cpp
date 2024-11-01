#include "WoodProducerLevelTwoUpgrade.h"
#include "entities/industry/woodproducer/WoodProducerLevelThreeUpgrade.h"

WoodProducerLevelTwoUpgrade::WoodProducerLevelTwoUpgrade(WoodProducer *woodProducer) : WoodProducerUpgrade(woodProducer) {}
WoodProducerLevelTwoUpgrade::WoodProducerLevelTwoUpgrade(WoodProducerLevelTwoUpgrade *woodProd) : WoodProducerUpgrade(woodProd) {}
WoodProducerLevelTwoUpgrade::~WoodProducerLevelTwoUpgrade() {}

void WoodProducerLevelTwoUpgrade::update()
{
    woodProducer->update();
}

int WoodProducerLevelTwoUpgrade::getLevel()
{
    return 2;
}

Entity *WoodProducerLevelTwoUpgrade::clone()
{
    return new WoodProducerLevelTwoUpgrade(this);
}

int WoodProducerLevelTwoUpgrade::getOutput()
{
    return woodProducer->getOutput() * UPGRADE;
}

Cost WoodProducerLevelTwoUpgrade::getCost()
{
    return Cost(woodProducer->getCost().moneyCost * UPGRADE, woodProducer->getCost().woodCost * UPGRADE, woodProducer->getCost().stoneCost * UPGRADE, woodProducer->getCost().concreteCost * UPGRADE);
}

Entity* WoodProducerLevelTwoUpgrade::upgrade()
{
    return new WoodProducerLevelThreeUpgrade(woodProducer);
}
