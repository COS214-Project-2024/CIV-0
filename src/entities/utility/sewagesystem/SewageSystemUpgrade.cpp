#include "SewageSystemUpgrade.h"

SewageSystemUpgrade::SewageSystemUpgrade(SewageSystem* sewage) : SewageSystem(sewage) {
    this->sewageSystem = new SewageSystem(sewage);
}

SewageSystemUpgrade::SewageSystemUpgrade(SewageSystemUpgrade* sSU) : SewageSystem(sSU) {
    this->sewageSystem = new SewageSystem(sSU->sewageSystem);
}

SewageSystemUpgrade::~SewageSystemUpgrade() {
    if(sewageSystem != nullptr) {
        delete sewageSystem;
        sewageSystem = nullptr;
    }
}