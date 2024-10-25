#include "StoneProducerLevelOneUpgrade.h"

StoneProducerLevelOneUpgrade::StoneProducerLevelOneUpgrade(StoneProducer* stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelOneUpgrade::StoneProducerLevelOneUpgrade(StoneProducerLevelOneUpgrade* stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelOneUpgrade::~StoneProducerLevelOneUpgrade() {}

void StoneProducerLevelOneUpgrade::update() {
    stoneProducer->update();
}

Entity* StoneProducerLevelOneUpgrade::clone() {
    return new StoneProducerLevelOneUpgrade(this);
}

int StoneProducerLevelOneUpgrade::getOutput() {
    return stoneProducer->getOutput() * UPGRADE;
}