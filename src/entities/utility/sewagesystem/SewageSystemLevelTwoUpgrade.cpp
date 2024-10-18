#include "SewageSystemLevelTwoUpgrade.h"

SewageSystemLevelTwoUpgrade::SewageSystemLevelTwoUpgrade(SewageSystem* sewageSystem) : SewageSystemUpgrade(sewageSystem) {

}

SewageSystemLevelTwoUpgrade::SewageSystemLevelTwoUpgrade(SewageSystemLevelTwoUpgrade* sewageSystemLevelTwoUpgrade) : SewageSystemUpgrade(sewageSystemLevelTwoUpgrade) {
    
}

SewageSystemLevelTwoUpgrade::~SewageSystemLevelTwoUpgrade() {

}

void SewageSystemLevelTwoUpgrade::update() {
    sewageSystem->update();
}

Entity* SewageSystemLevelTwoUpgrade::clone() {
    return new SewageSystemLevelTwoUpgrade(this);
}

int SewageSystemLevelTwoUpgrade::getOutput() {
    return sewageSystem->getOutput() * UPGRADE;
}