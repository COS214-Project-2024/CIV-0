#include "StoneProducer.h"

StoneProducer::StoneProducer() {}
StoneProducer::~StoneProducer() {}
StoneProducer::StoneProducer(StoneProducer* stoneProducer) : Industry(stoneProducer) {}
StoneProducer::StoneProducer(EntityConfig ec, Size size, int xPos, int yPos) : Industry(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

void StoneProducer::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateIndustry(this);
        }
    }

    if(!isBuilt()) {
        updateBuildState();
    }
}


Entity* StoneProducer::clone()
{
    return new StoneProducer(this);
}