#include "WasteManagementUpgrade.h"

WasteManagementUpgrade::WasteManagementUpgrade(WasteManagement* wasteManagement) : WasteManagement(wasteManagement) {
    this->wasteManagement = wasteManagement;
}

WasteManagementUpgrade::WasteManagementUpgrade(WasteManagementUpgrade* wasteManagementUpgrade) : WasteManagement(wasteManagementUpgrade) {
    this->wasteManagement = wasteManagementUpgrade->wasteManagement;
}

WasteManagementUpgrade::~WasteManagementUpgrade() {
    
}
