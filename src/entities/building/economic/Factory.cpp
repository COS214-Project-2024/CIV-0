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
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateFactory(this);
        }
    }
}

Entity* Factory::clone()
{
    return new Factory(this);
}