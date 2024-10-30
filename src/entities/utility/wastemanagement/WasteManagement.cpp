#include "WasteManagement.h"
#include "entities/utility/wastemanagement/WasteManagementLevelOneUpgrade.h"

WasteManagement::WasteManagement() : Utility() {

}

WasteManagement::~WasteManagement() {

}

WasteManagement::WasteManagement(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos) {
    setOutput(20); //TODO - change value
}

WasteManagement::WasteManagement(WasteManagement* waste) : Utility(waste) {

}

void WasteManagement::update() {
    for(Entity* o : observers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateUtility(this);
        }
    }
    
    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* WasteManagement::clone() {
    return new WasteManagement(this);
}

Entity* WasteManagement::upgrade() {
    return new WasteManagementLevelOneUpgrade(this);
}