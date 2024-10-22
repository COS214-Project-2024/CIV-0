#include "PowerPlant.h"

PowerPlant::PowerPlant() {}
PowerPlant::~PowerPlant() {}

PowerPlant::PowerPlant(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

void PowerPlant::update()
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

Entity* PowerPlant::clone()
{
    Entity* e = new PowerPlant(*ec, size, xPosition, yPosition);
    return e;
}