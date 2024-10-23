#include "Airport.h"

Airport::Airport(EntityConfig ec, Size size, int xPos, int yPos) : Transport(ec, size, xPos, yPos)
{

}

Airport::Airport(Airport* airport) : Transport(airport)
{

}

Airport::Airport() {}
Airport::~Airport() {}

void Airport::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateAirport(this);
        }
    }
}

Entity* Airport::clone()
{
    Entity* e = new Airport(*ec, size, xPosition, yPosition);
    return e;
}
