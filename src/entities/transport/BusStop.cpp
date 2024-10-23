#include "BusStop.h"

BusStop::BusStop(EntityConfig ec, Size size, int xPos, int yPos) : Transport(ec, size, xPos, yPos)
{

}

BusStop::BusStop(BusStop* busStop) : Transport(busStop)
{

}

BusStop::BusStop() {}
BusStop::~BusStop() {}

void BusStop::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateBusStop(this);
        }
    }
}

Entity* BusStop::clone()
{
    Entity* e = new BusStop(*ec, size, xPosition, yPosition);
    return e;
}
