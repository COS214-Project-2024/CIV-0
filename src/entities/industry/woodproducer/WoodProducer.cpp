#include "WoodProducer.h"

WoodProducer::WoodProducer() {}
WoodProducer::~WoodProducer() {}

WoodProducer::WoodProducer(EntityConfig ec, Size size, int xPos, int yPos) : Industry(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

WoodProducer::WoodProducer(WoodProducer* woodProducer): Industry(woodProducer)
{
    
}

void WoodProducer::update()
{
    for(Entity* o : observers)
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
    return new WoodProducer(this);
}