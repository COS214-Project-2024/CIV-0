#include "StoneProducer.h"

StoneProducer::StoneProducer() {}
StoneProducer::~StoneProducer() {}

StoneProducer::StoneProducer(EntityConfig ec, Size size, int xPos, int yPos) : Industry(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

StoneProducer::StoneProducer(StoneProducer* stoneProducer): Industry(stoneProducer)
{
    
}

void StoneProducer::update()
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

Entity* StoneProducer::clone()
{
    return new StoneProducer(this);
}