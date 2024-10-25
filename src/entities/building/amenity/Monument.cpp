#include "Monument.h"

Monument::Monument() {}
Monument::~Monument() {}

Monument::Monument(EntityConfig ec, Size size, int xPos, int yPos) : Amenity(ec, size, xPos, yPos)
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
}

Entity* Monument::clone()
{
    Entity* e = new Monument(*ec, size, xPosition, yPosition);
    return e;
}

void Monument::subscribeToAllResidentialInRadius()
{
    City* c = City::instance();

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            if(c->getEntity(i, j))
            {
                if(isWithinEffectRadius(c->getEntity(i, j)))
                {
                    subscribe(c->getEntity(i, j));
                }
            }
        }
    }
}
