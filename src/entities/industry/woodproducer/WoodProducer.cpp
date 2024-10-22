#include "WoodProducer.h"

WoodProducer::WoodProducer() {}
WoodProducer::~WoodProducer() {}

WoodProducer::WoodProducer(EntityConfig ec, Size size, int xPos, int yPos) : Industry(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

void WoodProducer::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateIndustry(this);
        }
    }
}

Entity* WoodProducer::clone()
{
    Entity* e = new WoodProducer(*ec, size, xPosition, yPosition);
    return e;
}