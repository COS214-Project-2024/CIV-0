#include "Theater.h"

Theater::Theater() {}
Theater::~Theater() {}

Theater::Theater(EntityConfig ec, Size size, int xPos, int yPos) : Amenity(ec, size, xPos, yPos)
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
}

Entity* Theater::clone()
{
    return new Theater(this);
}

Theater::Theater(Theater* theater) : Amenity(theater)
{

}