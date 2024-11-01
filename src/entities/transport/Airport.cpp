#include "Airport.h"

Airport::Airport(EntityConfig ec, Size size, int xPos, int yPos) : Transport(ec, size, xPos, yPos)
{

}

Airport::Airport(Airport* airport) : Transport(airport)
{

}

Airport::~Airport() {}

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

    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* Airport::clone()
{
    return new Airport(this);
}
