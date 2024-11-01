#include "WasteManagementUpgrade.h"

WasteManagementUpgrade::WasteManagementUpgrade(WasteManagement *waste) : WasteManagement(waste)
{
    this->wasteManagement = new WasteManagement(waste);
}

WasteManagementUpgrade::WasteManagementUpgrade(WasteManagementUpgrade *wasteManagementUpgrade) : WasteManagement(wasteManagementUpgrade)
{
    this->wasteManagement = new WasteManagement(wasteManagementUpgrade->wasteManagement);
}

WasteManagementUpgrade::~WasteManagementUpgrade()
{
    if (wasteManagement != nullptr)
    {
        delete wasteManagement;
        wasteManagement = nullptr;
    }
}