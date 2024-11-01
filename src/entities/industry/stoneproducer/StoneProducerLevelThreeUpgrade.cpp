#include "StoneProducerLevelThreeUpgrade.h"

StoneProducerLevelThreeUpgrade::StoneProducerLevelThreeUpgrade(StoneProducer *stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelThreeUpgrade::StoneProducerLevelThreeUpgrade(StoneProducerLevelThreeUpgrade *stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelThreeUpgrade::~StoneProducerLevelThreeUpgrade() {}

Entity *StoneProducerLevelThreeUpgrade::clone()
{
    return new StoneProducerLevelThreeUpgrade(this);
}

Entity *StoneProducerLevelThreeUpgrade::upgrade()
{
    return nullptr;
}

int StoneProducerLevelThreeUpgrade::getLevel()
{
    return 3;
}

int StoneProducerLevelThreeUpgrade::getOutput()
{
    return stoneProducer->getOutput() * UPGRADE;
}

void StoneProducerLevelThreeUpgrade::update()
{
    stoneProducer->update();
}

Cost StoneProducerLevelThreeUpgrade::getCost()
{
    return Cost(stoneProducer->getCost().moneyCost * UPGRADE, stoneProducer->getCost().woodCost * UPGRADE, stoneProducer->getCost().stoneCost * UPGRADE, stoneProducer->getCost().concreteCost * UPGRADE);
}
