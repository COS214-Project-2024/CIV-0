#include "StoneProducerLevelThreeUpgrade.h"

StoneProducerLevelThreeUpgrade::StoneProducerLevelThreeUpgrade(StoneProducer* stoneProd) : StoneProducerLevelThreeUpgrade(stoneProd) {}

StoneProducerLevelThreeUpgrade::StoneProducerLevelThreeUpgrade(StoneProducerLevelThreeUpgrade* stoneProd) : StoneProducerLevelThreeUpgrade(stoneProd) {}

StoneProducerLevelThreeUpgrade::~StoneProducerLevelThreeUpgrade() {}

Entity* StoneProducerLevelThreeUpgrade::clone() {
    return new StoneProducerLevelThreeUpgrade(this);
}

void StoneProducerLevelThreeUpgrade::update() {
    stoneProducer->update();
}

int StoneProducerLevelThreeUpgrade::getOutput() {
    return stoneProducer->getOutput() * UPGRADE;
}