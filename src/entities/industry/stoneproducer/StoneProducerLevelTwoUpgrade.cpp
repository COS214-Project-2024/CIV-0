
#include "StoneProducerLevelTwoUpgrade.h"

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