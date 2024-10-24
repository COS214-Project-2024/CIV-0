#include "Hospital.h"

Hospital::Hospital() {}
Hospital::~Hospital() {}

Hospital::Hospital(EntityConfig ec, Size size, int xPos, int yPos) : ServiceBuilding(ec, size, xPos, yPos)
{

}

void Hospital::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateHospital(this);
        }
    }
}

Entity* Hospital::clone()
{
    Entity* e = new Hospital(*ec, size, xPosition, yPosition);
    return e;
}