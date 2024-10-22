#include "WasteManagement.h"

WasteManagement::WasteManagement(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Utility(20, electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime) {
    //TODO - change value of output (1st param in Utility constructor)
}

WasteManagement::WasteManagement(WasteManagement* wasteManagement) : Utility(wasteManagement) {

}

WasteManagement::WasteManagement() : Utility() {

}

WasteManagement::~WasteManagement() {

}

void WasteManagement::update() {
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

Entity* WasteManagement::clone() {
    return new WasteManagement(this);
}