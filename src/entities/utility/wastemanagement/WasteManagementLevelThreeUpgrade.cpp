#include "WasteManagementLevelThreeUpgrade.h"

WasteManagementLevelThreeUpgrade::WasteManagementLevelThreeUpgrade(WasteManagement* wasteManagement) : WasteManagementUpgrade(wasteManagement) {

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

int WasteManagementLevelThreeUpgrade::getOutput() {
    return wasteManagement->getOutput() * UPGRADE;
}
