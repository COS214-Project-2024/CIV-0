#include "WoodProducerLevelOneUpgrade.h"

WoodProducerLevelOneUpgrade::WoodProducerLevelOneUpgrade() {}

WoodProducerLevelOneUpgrade::~WoodProducerLevelOneUpgrade() {}

Entity* WoodProducerLevelOneUpgrade::clone() {
    return new WoodProducerLevelOneUpgrade(this);
}