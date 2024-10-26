#include "ConcreteProducer.h"

ConcreteProducer::ConcreteProducer() : Industry() {}
ConcreteProducer::~ConcreteProducer() {}

ConcreteProducer::ConcreteProducer(EntityConfig ec, Size size, int xPos, int yPos) : Industry(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}


ConcreteProducer::ConcreteProducer(ConcreteProducer* concreteProducer): Industry(concreteProducer)
{
    
}

void ConcreteProducer::update()
{
    for(Entity* o : observers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateIndustry(this);
        }
    }

    if(!isBuilt) {
        updateBuildState();
    }
}

Entity* ConcreteProducer::clone()
{
    return new ConcreteProducer(this);
}