#include "Factory.h"

Factory::Factory() {}
Factory::~Factory() {}

Factory::Factory(EntityConfig ec, Size size, int xPos, int yPos) : EconomicBuilding(ec, size, xPos, yPos)
{

}

Factory::Factory(Factory* factory) : EconomicBuilding(factory)
{

}

void Factory::update()
{
    for(Entity* o : observers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateFactory(this);
        }
    }

    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* Factory::clone()
{
    return new Factory(this);
}