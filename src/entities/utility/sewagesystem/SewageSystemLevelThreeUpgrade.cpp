#include "SewageSystemLevelThreeUpgrade.h"

SewageSystemLevelThreeUpgrade::SewageSystemLevelThreeUpgrade(SewageSystem* sewageSystem) : SewageSystemUpgrade(sewageSystem) {

}

SewageSystemLevelThreeUpgrade::SewageSystemLevelThreeUpgrade(SewageSystemLevelThreeUpgrade* sewageSystemLevelThreeUpgrade) : SewageSystemUpgrade(sewageSystemLevelThreeUpgrade) {

}

SewageSystemLevelThreeUpgrade::~SewageSystemLevelThreeUpgrade() {
    
}

void SewageSystemLevelThreeUpgrade::update() {
    sewageSystem->update();
}

Entity* SewageSystemLevelThreeUpgrade::clone() {
    return new SewageSystemLevelThreeUpgrade(this);
}

int SewageSystemLevelThreeUpgrade::getOutput() {
    return sewageSystem->getOutput() * UPGRADE;
}
