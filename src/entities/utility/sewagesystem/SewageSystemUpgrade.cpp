#include "SewageSystemUpgrade.h"

SewageSystemUpgrade::SewageSystemUpgrade(SewageSystem* sewageSystem) : SewageSystem(sewageSystem) {
    this->sewageSystem = sewageSystem;
}

SewageSystemUpgrade::SewageSystemUpgrade(SewageSystemUpgrade* sewageSystemUpgrade) : SewageSystem(sewageSystemUpgrade) {
    this->sewageSystem = sewageSystemUpgrade->sewageSystem;
}

SewageSystemUpgrade::~SewageSystemUpgrade() {
    
}
