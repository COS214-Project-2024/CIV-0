#include "WasteManagementLevelOneUpgrade.h"

WasteManagementLevelOneUpgrade::WasteManagementLevelOneUpgrade(WasteManagement* wasteManagement) : WasteManagementUpgrade(wasteManagement) {

}

WasteManagementLevelOneUpgrade::WasteManagementLevelOneUpgrade(WasteManagementLevelOneUpgrade* wasteManagementLevelOneUpgrade) : WasteManagementUpgrade(wasteManagementLevelOneUpgrade) {

}

WasteManagementLevelOneUpgrade::~WasteManagementLevelOneUpgrade() {

}

void WasteManagementLevelOneUpgrade::update() {
    wasteManagement->update();
}

Entity* WasteManagementLevelOneUpgrade::clone() {
    return new WasteManagementLevelOneUpgrade(this);
}

int WasteManagementLevelOneUpgrade::getOutput() {
    return wasteManagement->getOutput() * UPGRADE;
}
