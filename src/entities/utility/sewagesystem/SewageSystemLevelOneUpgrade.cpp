#include "SewageSystemLevelOneUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include <iostream>

SewageSystemLevelOneUpgrade::SewageSystemLevelOneUpgrade(SewageSystem* sewage) : SewageSystemUpgrade(sewage) {

}

SewageSystemLevelOneUpgrade::SewageSystemLevelOneUpgrade(SewageSystemLevelOneUpgrade* sSLOU) : SewageSystemUpgrade(sSLOU) {

}

SewageSystemLevelOneUpgrade::~SewageSystemLevelOneUpgrade() {

}

void SewageSystemLevelOneUpgrade::update() {
    sewageSystem->update();
}

Entity* SewageSystemLevelOneUpgrade::clone() {
    return new SewageSystemLevelOneUpgrade(this);
}

Entity* SewageSystemLevelOneUpgrade::upgrade() {
    return new SewageSystemLevelTwoUpgrade(sewageSystem);
}

int SewageSystemLevelOneUpgrade::getOutput() {
    return sewageSystem->getOutput() * UPGRADE;
}

Cost SewageSystemLevelOneUpgrade::getCost() {
    return Cost(sewageSystem->getCost().moneyCost*UPGRADE, sewageSystem->getCost().woodCost*UPGRADE, sewageSystem->getCost().stoneCost*UPGRADE, sewageSystem->getCost().concreteCost*UPGRADE);
}