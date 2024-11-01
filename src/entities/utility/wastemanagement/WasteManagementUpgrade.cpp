#include "WasteManagementUpgrade.h"

WasteManagementUpgrade::WasteManagementUpgrade(WasteManagement* waste) : WasteManagement(waste) {
    this->wasteManagement = new WasteManagement(waste);
}

WasteManagementUpgrade::WasteManagementUpgrade(WasteManagementUpgrade* wMU) : WasteManagement(wMU) {
    this->wasteManagement = new WasteManagement(wMU->wasteManagement);
}

WasteManagementUpgrade::~WasteManagementUpgrade() {
    if(wasteManagement != nullptr) {
        delete wasteManagement;
        wasteManagement = nullptr;
    }
}