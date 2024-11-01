#include "WasteManagementLevelThreeUpgrade.h"

WasteManagementLevelThreeUpgrade::WasteManagementLevelThreeUpgrade(WasteManagement *waste) : WasteManagementUpgrade(waste)
{
}

WasteManagementLevelThreeUpgrade::WasteManagementLevelThreeUpgrade(WasteManagementLevelThreeUpgrade *wasteManagementLevelThreeUpgrade) : WasteManagementUpgrade(wasteManagementLevelThreeUpgrade)
{
}

WasteManagementLevelThreeUpgrade::~WasteManagementLevelThreeUpgrade()
{
}

void WasteManagementLevelThreeUpgrade::update()
{
    wasteManagement->update();
}

int WasteManagementLevelThreeUpgrade::getLevel()
{
    return 3;
}

Entity *WasteManagementLevelThreeUpgrade::clone()
{
    return new WasteManagementLevelThreeUpgrade(this);
}

Entity *WasteManagementLevelThreeUpgrade::upgrade()
{
    // Maximum level reached
    return nullptr;
}

int WasteManagementLevelThreeUpgrade::getOutput()
{
    return wasteManagement->getOutput() * UPGRADE;
}

Cost WasteManagementLevelThreeUpgrade::getCost()
{
    return Cost(wasteManagement->getCost().moneyCost * UPGRADE, wasteManagement->getCost().woodCost * UPGRADE, wasteManagement->getCost().stoneCost * UPGRADE, wasteManagement->getCost().concreteCost * UPGRADE);
}