#include "WasteManagementLevelTwoUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelThreeUpgrade.h"

WasteManagementLevelTwoUpgrade::WasteManagementLevelTwoUpgrade(WasteManagement* waste) : WasteManagementUpgrade(waste) {

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

Entity* WasteManagementLevelTwoUpgrade::upgrade() {
    return new WasteManagementLevelThreeUpgrade(wasteManagement);
}

int WasteManagementLevelTwoUpgrade::getOutput() {
    return wasteManagement->getOutput() * UPGRADE;
}

Cost WasteManagementLevelTwoUpgrade::getCost() {
    return Cost(wasteManagement->getCost().moneyCost*UPGRADE, wasteManagement->getCost().woodCost*UPGRADE, wasteManagement->getCost().stoneCost*UPGRADE, wasteManagement->getCost().concreteCost*UPGRADE);
}