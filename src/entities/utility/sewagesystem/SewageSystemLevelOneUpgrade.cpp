#include "SewageSystemLevelOneUpgrade.h"

SewageSystemLevelOneUpgrade::SewageSystemLevelOneUpgrade(SewageSystem* sewageSystem) : SewageSystemUpgrade(sewageSystem) {

}

SewageSystemLevelOneUpgrade::SewageSystemLevelOneUpgrade(SewageSystemLevelOneUpgrade* sewageSystemLevelOneUpgrade) : SewageSystemUpgrade(sewageSystemLevelOneUpgrade) {

}

SewageSystemLevelOneUpgrade::~SewageSystemLevelOneUpgrade() {

}

void SewageSystemLevelOneUpgrade::update() {
    sewageSystem->update();
}

Entity* SewageSystemLevelOneUpgrade::clone() {
    return new SewageSystemLevelOneUpgrade(this);
}

int SewageSystemLevelOneUpgrade::getOutput() {
    return sewageSystem->getOutput() * UPGRADE;
}
