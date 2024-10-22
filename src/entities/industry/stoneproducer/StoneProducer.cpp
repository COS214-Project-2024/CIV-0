#include "StoneProducer.h"

StoneProducer::StoneProducer() {}
StoneProducer::~StoneProducer() {}

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
}

Entity* StoneProducer::clone()
{
    Entity* e = new StoneProducer(*ec, size, xPosition, yPosition);
    return e;
}