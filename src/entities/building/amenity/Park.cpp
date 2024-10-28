#include "Park.h"

Park::Park() {}
Park::~Park() {}

Park::Park(EntityConfig ec, Size size, int xPos, int yPos) : Amenity(ec, size, xPos, yPos)
{

}

Park::Park(Park* park) : Amenity(park)
{
    
}

void Park::update()
{
    for(Entity* o : observers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateAmenity(this);
        }
    }

    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* Park::clone()
{
    return new Park(this);
    return new Park(this);
}