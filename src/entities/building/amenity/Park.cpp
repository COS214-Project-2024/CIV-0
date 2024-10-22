#include "Park.h"

Park::Park() {}
Park::~Park() {}

Park::Park(EntityConfig ec, Size size, int xPos, int yPos) : Amenity(ec, size, xPos, yPos)
{

}

void Park::update()
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

Entity* Park::clone()
{
    Entity* e = new Park(*ec, size, xPosition, yPosition);
    return e;
}