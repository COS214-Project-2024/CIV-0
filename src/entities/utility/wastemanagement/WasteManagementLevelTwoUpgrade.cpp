#include "WasteManagementLevelTwoUpgrade.h"

WasteManagementLevelTwoUpgrade::WasteManagementLevelTwoUpgrade(WasteManagement* wasteManagement) : WasteManagementUpgrade(wasteManagement) {

}

WasteManagementLevelTwoUpgrade::WasteManagementLevelTwoUpgrade(WasteManagementLevelTwoUpgrade* wasteManagementLevelTwoUpgrade) : WasteManagementUpgrade(wasteManagementLevelTwoUpgrade) {

}

WasteManagementLevelTwoUpgrade::~WasteManagementLevelTwoUpgrade() {
    
}

void WasteManagementLevelTwoUpgrade::update() {
    wasteManagement->update();
}

Entity* WasteManagementLevelTwoUpgrade::clone() {
    return new WasteManagementLevelTwoUpgrade(this);
}

int WasteManagementLevelTwoUpgrade::getOutput() {
    return wasteManagement->getOutput() * UPGRADE;
}
