
#include "WoodProducerLevelThreeUpgrade.h"

WoodProducerLevelThreeUpgrade::WoodProducerLevelThreeUpgrade(WoodProducer *woodProd) : WoodProducerUpgrade(woodProd) {}

WoodProducerLevelThreeUpgrade::~WoodProducerLevelThreeUpgrade() {}

WoodProducerLevelThreeUpgrade::WoodProducerLevelThreeUpgrade(WoodProducerLevelThreeUpgrade *woodProd) : WoodProducerUpgrade(woodProd)
{
}

void WoodProducerLevelThreeUpgrade::update()
{
    woodProducer->update();
}

int WoodProducerLevelThreeUpgrade::getLevel()
{
    return 3;
}

Entity *WoodProducerLevelThreeUpgrade::clone()
{
    return new WoodProducerLevelThreeUpgrade(this);
}

int WoodProducerLevelThreeUpgrade::getOutput()
{
    return this->woodProducer->getOutput() * UPGRADE;
}

Cost WoodProducerLevelThreeUpgrade::getCost()
{
    return Cost(woodProducer->getCost().moneyCost * UPGRADE, woodProducer->getCost().woodCost * UPGRADE, woodProducer->getCost().stoneCost * UPGRADE, woodProducer->getCost().concreteCost * UPGRADE);
}

Entity* WoodProducerLevelThreeUpgrade::upgrade()
{
    return nullptr;
}