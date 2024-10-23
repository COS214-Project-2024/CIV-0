#include "WasteManagement.h"

WasteManagement::WasteManagement() : Utility() {}
WasteManagement::~WasteManagement() {}

WasteManagement::WasteManagement(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

WasteManagement::WasteManagement(WasteManagement* wasteManagement) : Utility(wasteManagement) {

}

void WasteManagement::update()
{
    for(Observer* o : subscribers)
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

Entity* WasteManagement::clone()
{
    return new WasteManagement(this);
}