#include "PoliceStation.h"

PoliceStation::~PoliceStation() {}

PoliceStation::PoliceStation(EntityConfig ec, Size size, int xPos, int yPos) : ServiceBuilding(ec, size, xPos, yPos)
{

}

PoliceStation::PoliceStation(PoliceStation* police) : ServiceBuilding(police)
{

}

void PoliceStation::update()
{
    for(Entity* o : observers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updatePoliceStation(this);
        }
    }

    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* PoliceStation::clone()
{
    return new PoliceStation(this);
}