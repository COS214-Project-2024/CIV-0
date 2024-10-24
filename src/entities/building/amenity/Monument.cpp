#include "Monument.h"

Monument::Monument() {}
Monument::~Monument() {}

Monument::Monument(EntityConfig ec, Size size, int xPos, int yPos) : Amenity(ec, size, xPos, yPos)
{

}

Monument::Monument(Monument* monument) : Amenity(monument)
{

}

void Monument::update()
{
    for(Observer* o : subscribers)
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

Entity* Monument::clone()
{
    return new Monument(this);
}
