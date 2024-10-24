#include "Theater.h"

Theater::Theater() {}
Theater::~Theater() {}

Theater::Theater(EntityConfig ec, Size size, int xPos, int yPos) : Amenity(ec, size, xPos, yPos)
{

}

void Theater::update()
{
    for(Observer* o : subscribers)
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
    Entity* e = new Theater(*ec, size, xPosition, yPosition);
    return e;
}