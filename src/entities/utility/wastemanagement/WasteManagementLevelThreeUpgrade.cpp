#include "WasteManagementLevelThreeUpgrade.h"

WasteManagementLevelThreeUpgrade::WasteManagementLevelThreeUpgrade(WasteManagement* waste) : WasteManagementUpgrade(waste) {

}

WasteManagementLevelThreeUpgrade::WasteManagementLevelThreeUpgrade(WasteManagementLevelThreeUpgrade* wasteManagementLevelThreeUpgrade) : WasteManagementUpgrade(wasteManagementLevelThreeUpgrade) {

}

WasteManagementLevelThreeUpgrade::~WasteManagementLevelThreeUpgrade() {
    
}

void WasteManagementLevelThreeUpgrade::update() {
    wasteManagement->update();
}

Entity* WasteManagementLevelThreeUpgrade::clone() {
    return new WasteManagementLevelThreeUpgrade(this);
}

Entity* WasteManagementLevelThreeUpgrade::upgrade() {
    return this;
}

int WasteManagementLevelThreeUpgrade::getOutput() {
    return wasteManagement->getOutput() * UPGRADE;
}
