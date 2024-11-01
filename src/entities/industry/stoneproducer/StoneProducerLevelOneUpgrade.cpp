#include "StoneProducerLevelOneUpgrade.h"
#include "entities/industry/stoneproducer/StoneProducerLevelTwoUpgrade.h"

StoneProducerLevelOneUpgrade::StoneProducerLevelOneUpgrade(StoneProducer *stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelOneUpgrade::StoneProducerLevelOneUpgrade(StoneProducerLevelOneUpgrade *stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelOneUpgrade::~StoneProducerLevelOneUpgrade() {}

Entity* StoneProducerLevelOneUpgrade::upgrade()
{
    return new StoneProducerLevelTwoUpgrade(stoneProducer);
}

int StoneProducerLevelOneUpgrade::getLevel()
{
    return 1;
}

Entity *StoneProducerLevelOneUpgrade::clone()
{
    return new StoneProducerLevelOneUpgrade(this);
}

int StoneProducerLevelOneUpgrade::getOutput()
{
    return stoneProducer->getOutput() * UPGRADE;
}

void StoneProducerLevelOneUpgrade::update()
{
    stoneProducer->update();
}

Cost StoneProducerLevelOneUpgrade::getCost()
{
    return Cost(stoneProducer->getCost().moneyCost * UPGRADE, stoneProducer->getCost().woodCost * UPGRADE, stoneProducer->getCost().stoneCost * UPGRADE, stoneProducer->getCost().concreteCost * UPGRADE);
}