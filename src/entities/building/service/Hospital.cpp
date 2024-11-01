#include "Hospital.h"

Hospital::~Hospital() {}

Hospital::Hospital(EntityConfig ec, Size size, int xPos, int yPos) : ServiceBuilding(ec, size, xPos, yPos)
{

}

Hospital::Hospital(Hospital* hospital) : ServiceBuilding(hospital)
{

}

void Hospital::update()
{
    for(Entity* o : observers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateHospital(this);
        }
    }

    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* Hospital::clone()
{
    return new Hospital(this);
}