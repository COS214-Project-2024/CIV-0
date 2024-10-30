#include "PowerPlant.h"
#include "entities/utility/powerplant/PowerPlantLevelOneUpgrade.h"

PowerPlant::PowerPlant() : Utility() {

}

PowerPlant::~PowerPlant() {
    
}

PowerPlant::PowerPlant(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos) {
    setOutput(20); //TODO - change value
}

PowerPlant::PowerPlant(PowerPlant* power) : Utility(power) {

}

void PowerPlant::update() {
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

Entity* PowerPlant::clone() {
    return new PowerPlant(this);
}

Entity* PowerPlant::upgrade() {
    return new PowerPlantLevelOneUpgrade(this);
}