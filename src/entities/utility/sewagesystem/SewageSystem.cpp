#include "SewageSystem.h"

SewageSystem::SewageSystem() : Utility() {}
SewageSystem::~SewageSystem() {}

SewageSystem::SewageSystem(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

SewageSystem::SewageSystem(SewageSystem* sewageSystem) : Utility(sewageSystem) {

}

void SewageSystem::update()
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

Entity* SewageSystem::clone()
{
    return new SewageSystem(this);
}