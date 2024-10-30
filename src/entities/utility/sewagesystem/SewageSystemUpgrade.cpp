#include "SewageSystemUpgrade.h"
#include <iostream>

SewageSystemUpgrade::SewageSystemUpgrade(SewageSystem* sewage) : SewageSystem(sewage) {
    this->sewageSystem = sewage;
}

SewageSystemUpgrade::SewageSystemUpgrade(SewageSystemUpgrade* sewageSystemUpgrade) : SewageSystem(sewageSystemUpgrade) {
    this->sewageSystem = sewageSystemUpgrade->sewageSystem;
}

SewageSystemUpgrade::~SewageSystemUpgrade() {
    
}
