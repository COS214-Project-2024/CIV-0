#include "SewageSystem.h"

SewageSystem::SewageSystem(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Utility(20, electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime) {
    //TODO - change value of output (1st param in Utility constructor)
}

SewageSystem::SewageSystem(SewageSystem* sewageSystem) : Utility(sewageSystem) {

}

SewageSystem::SewageSystem() : Utility() {

}

SewageSystem::~SewageSystem() {

}

void SewageSystem::update() {
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

Entity* SewageSystem::clone() {
    return new SewageSystem(this);
}