#include "Hospital.h"

Hospital::Hospital() {}
Hospital::~Hospital() {}

Hospital::Hospital(EntityConfig ec, Size size, int xPos, int yPos) : ServiceBuilding(ec, size, xPos, yPos)
{

}

Hospital::Hospital(Hospital* hospital) : ServiceBuilding(hospital)
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
    return new Hospital(this);
}