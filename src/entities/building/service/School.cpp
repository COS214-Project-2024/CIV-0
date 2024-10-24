#include "School.h"

School::School() {}
School::~School() {}

School::School(EntityConfig ec, Size size, int xPos, int yPos) : ServiceBuilding(ec, size, xPos, yPos)
{

}

School::School(School* school) : ServiceBuilding(school)
{

}

void School::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateSchool(this);
        }
    }

    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* School::clone()
{
    return new School(this);
}
