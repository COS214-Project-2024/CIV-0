#include "StoneProducerLevelTwoUpgrade.h"

StoneProducerLevelTwoUpgrade::StoneProducerLevelTwoUpgrade(StoneProducer* stoneProd) : StoneProducerUpgrade(stoneProd) {}

StoneProducerLevelTwoUpgrade::StoneProducerLevelTwoUpgrade(StoneProducerLevelTwoUpgrade* stoneProd) : StoneProducerLevelTwoUpgrade(stoneProd){}

StoneProducerLevelTwoUpgrade::~StoneProducerLevelTwoUpgrade() {}

Entity* StoneProducerLevelTwoUpgrade::clone() {
    return new StoneProducerLevelTwoUpgrade(this);
}

int StoneProducerLevelTwoUpgrade::getOutput() {
    stoneProducer->getOutput() * UPGRADE;
}

void StoneProducerLevelTwoUpgrade::update() {
    stoneProducer->update();
}