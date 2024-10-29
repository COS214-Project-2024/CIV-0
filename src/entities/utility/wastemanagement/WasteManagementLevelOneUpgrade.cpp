#include "WasteManagementLevelOneUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"

WasteManagementLevelOneUpgrade::WasteManagementLevelOneUpgrade(WasteManagement* waste) : WasteManagementUpgrade(waste) {

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

Entity* WasteManagementLevelOneUpgrade::upgrade() {
    return new WasteManagementLevelTwoUpgrade(wasteManagement);
}

int WasteManagementLevelOneUpgrade::getOutput() {
    return wasteManagement->getOutput() * UPGRADE;
}