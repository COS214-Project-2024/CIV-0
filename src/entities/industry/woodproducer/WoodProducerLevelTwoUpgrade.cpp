#include "WoodProducerLevelTwoUpgrade.h"

WoodProducerLevelTwoUpgrade::WoodProducerLevelTwoUpgrade(WoodProducer *woodProducer) : WoodProducerUpgrade(woodProducer) {}
WoodProducerLevelTwoUpgrade::WoodProducerLevelTwoUpgrade(WoodProducerLevelTwoUpgrade* woodProd) : WoodProducerUpgrade(woodProd) {}
WoodProducerLevelTwoUpgrade::~WoodProducerLevelTwoUpgrade() {}

void WoodProducerLevelTwoUpgrade::update()
{
    woodProducer->update();
}

Entity *WoodProducerLevelTwoUpgrade::clone()
{
    return new WoodProducerLevelTwoUpgrade(this);
}

int WoodProducerLevelTwoUpgrade::getOutput()
{
    return woodProducer->getOutput() * UPGRADE;
}