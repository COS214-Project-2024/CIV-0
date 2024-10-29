#include "SewageSystem.h"
#include "entities/utility/SewageSystem/SewageSystemLevelOneUpgrade.h"

SewageSystem::SewageSystem() : Utility() {

}

SewageSystem::~SewageSystem() {

}

SewageSystem::SewageSystem(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos) {
    setOutput(20); //TODO - change value
}

SewageSystem::SewageSystem(SewageSystem* sewage) : Utility(sewage) {

}

void SewageSystem::update() {
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

Entity* SewageSystem::clone() {
    return new SewageSystem(this);
}

Entity* SewageSystem::upgrade() {
    return new SewageSystemLevelOneUpgrade(this);
}