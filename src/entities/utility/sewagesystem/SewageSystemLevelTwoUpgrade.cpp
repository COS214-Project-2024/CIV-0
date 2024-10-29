#include "SewageSystemLevelTwoUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"

SewageSystemLevelTwoUpgrade::SewageSystemLevelTwoUpgrade(SewageSystem* sewage) : SewageSystemUpgrade(sewage) {

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

Entity* SewageSystemLevelTwoUpgrade::upgrade() {
    return new SewageSystemLevelThreeUpgrade(sewageSystem);
}

int SewageSystemLevelTwoUpgrade::getOutput() {
    return sewageSystem->getOutput() * UPGRADE;
}
