#include "StoneProducerLevelTwoUpgrade.h"
#include "entities/industry/stoneproducer/StoneProducerLevelThreeUpgrade.h"

StoneProducerLevelTwoUpgrade::StoneProducerLevelTwoUpgrade(StoneProducer *stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelTwoUpgrade::StoneProducerLevelTwoUpgrade(StoneProducerLevelTwoUpgrade *stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelTwoUpgrade::~StoneProducerLevelTwoUpgrade() {}

Entity *StoneProducerLevelTwoUpgrade::clone()
{
    return new StoneProducerLevelTwoUpgrade(this);
}

int StoneProducerLevelTwoUpgrade::getOutput()
{
    return stoneProducer->getOutput() * UPGRADE;
}

int StoneProducerLevelTwoUpgrade::getLevel()
{
    return 2;
}

void StoneProducerLevelTwoUpgrade::update()
{
    stoneProducer->update();
}

Entity *StoneProducerLevelTwoUpgrade::upgrade()
{
    return new StoneProducerLevelThreeUpgrade(this);
}

Cost StoneProducerLevelTwoUpgrade::getCost()
{
    return Cost(stoneProducer->getCost().moneyCost * UPGRADE, stoneProducer->getCost().woodCost * UPGRADE, stoneProducer->getCost().stoneCost * UPGRADE, stoneProducer->getCost().concreteCost * UPGRADE);
}