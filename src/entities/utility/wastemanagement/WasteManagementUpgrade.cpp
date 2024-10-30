#include "WasteManagementUpgrade.h"

WasteManagementUpgrade::WasteManagementUpgrade(WasteManagement* waste) : WasteManagement(waste) {
    this->wasteManagement = waste;
}

WasteManagementUpgrade::WasteManagementUpgrade(WasteManagementUpgrade* wasteManagementUpgrade) : WasteManagement(wasteManagementUpgrade) {
    this->wasteManagement = wasteManagementUpgrade->wasteManagement;
}

WasteManagementUpgrade::~WasteManagementUpgrade() {
    
}
