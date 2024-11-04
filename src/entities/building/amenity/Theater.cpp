#include "Theater.h"

Theater::~Theater() {}

Theater::Theater(EntityConfig ec, Size size, int xPos, int yPos) : Amenity(ec, size, xPos, yPos)
{

}

Theater::Theater(Theater* theater) : Amenity(theater)
{
    
}

void Theater::update()
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

Entity* Theater::clone()
{
    return new Theater(this);
}