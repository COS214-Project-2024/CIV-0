#include "WoodProducerLevelThreeUpgrade.h"

WoodProducerLevelThreeUpgrade::WoodProducerLevelThreeUpgrade(WoodProducer* woodProd) : WoodProducerUpgrade(woodProd) {}

WoodProducerLevelThreeUpgrade::~WoodProducerLevelThreeUpgrade() {}

WoodProducerLevelThreeUpgrade::WoodProducerLevelThreeUpgrade(WoodProducerLevelThreeUpgrade* woodProd) : WoodProducerUpgrade(woodProd) {

}

void WoodProducerLevelThreeUpgrade::update()
{
    woodProducer->update();
}

Entity *WoodProducerLevelThreeUpgrade::clone()
{
    return new WoodProducerLevelThreeUpgrade(this);
}

int WoodProducerLevelThreeUpgrade::getOutput()
{
    return this->woodProducer->getOutput() * UPGRADE;
}