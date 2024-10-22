#include "SewageSystem.h"

SewageSystem::SewageSystem() {}
SewageSystem::~SewageSystem() {}

SewageSystem::SewageSystem(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
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
}

Entity* SewageSystem::clone()
{
    Entity* e = new SewageSystem(*ec, size, xPosition, yPosition);
    return e;
}