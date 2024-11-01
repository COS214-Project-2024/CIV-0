#include "WasteManagementLevelOneUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"

WasteManagementLevelOneUpgrade::WasteManagementLevelOneUpgrade(WasteManagement *waste) : WasteManagementUpgrade(waste)
{
}

WasteManagementLevelOneUpgrade::WasteManagementLevelOneUpgrade(WasteManagementLevelOneUpgrade *wMLOU) : WasteManagementUpgrade(wMLOU)
{
}

WasteManagementLevelOneUpgrade::~WasteManagementLevelOneUpgrade()
{
}

void WasteManagementLevelOneUpgrade::update()
{
    wasteManagement->update();
}

int WasteManagementLevelOneUpgrade::getLevel()
{
    return 1;
}

Entity *WasteManagementLevelOneUpgrade::clone()
{
    return new WasteManagementLevelOneUpgrade(this);
}

Entity *WasteManagementLevelOneUpgrade::upgrade()
{
    return new WasteManagementLevelTwoUpgrade(wasteManagement);
}

int WasteManagementLevelOneUpgrade::getOutput()
{
    return wasteManagement->getOutput() * UPGRADE;
}

Cost WasteManagementLevelOneUpgrade::getCost()
{
    return Cost(wasteManagement->getCost().moneyCost * UPGRADE, wasteManagement->getCost().woodCost * UPGRADE, wasteManagement->getCost().stoneCost * UPGRADE, wasteManagement->getCost().concreteCost * UPGRADE);
}