#include "StoneProducerLevelThreeUpgrade.h"

StoneProducerLevelThreeUpgrade::StoneProducerLevelThreeUpgrade(StoneProducer *stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelThreeUpgrade::StoneProducerLevelThreeUpgrade(StoneProducerLevelThreeUpgrade *stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelThreeUpgrade::~StoneProducerLevelThreeUpgrade() {}

Entity *StoneProducerLevelThreeUpgrade::clone()
{
    return new StoneProducerLevelThreeUpgrade(this);
}

void StoneProducerLevelThreeUpgrade::update()
{
    stoneProducer->update();
}

int StoneProducerLevelThreeUpgrade::getLevel()
{
    return 3;
}

int StoneProducerLevelThreeUpgrade::getOutput()
{
    return stoneProducer->getOutput() * UPGRADE;
}
