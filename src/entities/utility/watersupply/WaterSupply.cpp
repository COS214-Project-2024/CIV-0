#include "WaterSupply.h"

WaterSupply::WaterSupply() {}
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
}

Entity* WaterSupply::clone()
{
    Entity* e = new WaterSupply(*ec, size, xPosition, yPosition);
    return e;
}