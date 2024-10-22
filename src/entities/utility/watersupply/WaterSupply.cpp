#include "WaterSupply.h"

WaterSupply::WaterSupply() : Utility() {}
WaterSupply::~WaterSupply() {}

WaterSupply::WaterSupply(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

WaterSupply::WaterSupply(WaterSupply* waterSupply) : Utility(waterSupply) {

}

void WaterSupply::update()
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

Entity* WaterSupply::clone()
{
    return new WaterSupply(*ec, size, xPosition, yPosition);
}