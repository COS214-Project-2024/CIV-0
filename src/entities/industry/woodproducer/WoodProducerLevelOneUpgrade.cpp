
#include "WoodProducerLevelOneUpgrade.h"
#include "entities/industry/woodproducer/WoodProducerLevelTwoUpgrade.h"

WoodProducerLevelOneUpgrade::WoodProducerLevelOneUpgrade(WoodProducer *woodProducer) : WoodProducerUpgrade(woodProducer)
{
}

WoodProducerLevelOneUpgrade::WoodProducerLevelOneUpgrade(WoodProducerLevelOneUpgrade *WoodProd) : WoodProducerUpgrade(WoodProd) {}

WoodProducerLevelOneUpgrade::~WoodProducerLevelOneUpgrade() {}

Entity *WoodProducerLevelOneUpgrade::clone()
{
    return new WoodProducerLevelOneUpgrade(this);
}

void WoodProducerLevelOneUpgrade::update()
{
    woodProducer->update();
}

int WoodProducerLevelOneUpgrade::getLevel()
{
    return 1;
}

int WoodProducerLevelOneUpgrade::getOutput()
{
    return woodProducer->getOutput() * UPGRADE;
}

Cost WoodProducerLevelOneUpgrade::getCost()
{
    return Cost(woodProducer->getCost().moneyCost * UPGRADE, woodProducer->getCost().woodCost * UPGRADE, woodProducer->getCost().stoneCost * UPGRADE, woodProducer->getCost().concreteCost * UPGRADE);
}

Entity* WoodProducerLevelOneUpgrade::upgrade()
{
    return new WoodProducerLevelTwoUpgrade(woodProducer);
}
