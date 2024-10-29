#include "SewageSystemLevelThreeUpgrade.h"

SewageSystemLevelThreeUpgrade::SewageSystemLevelThreeUpgrade(SewageSystem* sewage) : SewageSystemUpgrade(sewage) {

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

Entity* SewageSystemLevelThreeUpgrade::upgrade() {
    return this;
}

int SewageSystemLevelThreeUpgrade::getOutput() {
    return sewageSystem->getOutput() * UPGRADE;
}
