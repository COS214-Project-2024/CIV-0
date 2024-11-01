#include "SewageSystemLevelThreeUpgrade.h"

SewageSystemLevelThreeUpgrade::SewageSystemLevelThreeUpgrade(SewageSystem* sewage) : SewageSystemUpgrade(sewage) {

}

SewageSystemLevelThreeUpgrade::SewageSystemLevelThreeUpgrade(SewageSystemLevelThreeUpgrade* sSLTU) : SewageSystemUpgrade(sSLTU) {

}

SewageSystemLevelThreeUpgrade::~SewageSystemLevelThreeUpgrade() {
    
}

void SewageSystemLevelThreeUpgrade::update() {
    sewageSystem->update();
}

Entity* SewageSystemLevelThreeUpgrade::clone() {
    return new SewageSystemLevelThreeUpgrade(this);
}

Entity* SewageSystemLevelThreeUpgrade::upgrade() {
    // Maximum level reached
    return nullptr;
}

int SewageSystemLevelThreeUpgrade::getOutput() {
    return sewageSystem->getOutput() * UPGRADE;
}

Cost SewageSystemLevelThreeUpgrade::getCost() {
    return Cost(sewageSystem->getCost().moneyCost*UPGRADE, sewageSystem->getCost().woodCost*UPGRADE, sewageSystem->getCost().stoneCost*UPGRADE, sewageSystem->getCost().concreteCost*UPGRADE);
}