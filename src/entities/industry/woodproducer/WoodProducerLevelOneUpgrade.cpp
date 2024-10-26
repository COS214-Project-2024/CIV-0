#include "WoodProducerLevelOneUpgrade.h"

WoodProducerLevelOneUpgrade::WoodProducerLevelOneUpgrade(WoodProducer* woodProducer) : WoodProducerUpgrade(woodProducer) {
    
}

WoodProducerLevelOneUpgrade::WoodProducerLevelOneUpgrade(WoodProducerLevelOneUpgrade* WoodProd) : WoodProducerUpgrade(WoodProd) {}

WoodProducerLevelOneUpgrade::~WoodProducerLevelOneUpgrade() {}


Entity *WoodProducerLevelOneUpgrade::clone()
{
    return new WoodProducerLevelOneUpgrade(this);
}

void WoodProducerLevelOneUpgrade::update()
{
    woodProducer->update();
}

int WoodProducerLevelOneUpgrade::getOutput()
{
    return woodProducer->getOutput() * UPGRADE;
}