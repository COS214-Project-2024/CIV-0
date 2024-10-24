#include "PoliceStation.h"

PoliceStation::PoliceStation() {}
PoliceStation::~PoliceStation() {}

PoliceStation::PoliceStation(EntityConfig ec, Size size, int xPos, int yPos) : ServiceBuilding(ec, size, xPos, yPos)
{

}

PoliceStation::PoliceStation(PoliceStation* police) : ServiceBuilding(police)
{
    
}

void PoliceStation::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updatePoliceStation(this);
        }
    }
}

Entity* PoliceStation::clone()
{
    Entity* e = new PoliceStation(*ec, size, xPosition, yPosition);
    return e;
}