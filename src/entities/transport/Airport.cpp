#include "Airport.h"

Airport::Airport(EntityConfig ec, Size size, int xPos, int yPos) : Transport(ec, size, xPos, yPos)
{

}

Airport::Airport() {}
Airport::~Airport() {}

Airport::Airport(Airport* airport) : Transport(airport) {

}

void Airport::update()
{
    for(Entity* o : observers)
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
    return new Airport(this);
}
