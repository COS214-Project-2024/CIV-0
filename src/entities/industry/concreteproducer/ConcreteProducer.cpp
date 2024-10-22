#include "ConcreteProducer.h"

ConcreteProducer::ConcreteProducer() {}
ConcreteProducer::~ConcreteProducer() {}

ConcreteProducer::ConcreteProducer(EntityConfig ec, Size size, int xPos, int yPos) : Industry(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

void ConcreteProducer::update()
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

Entity* ConcreteProducer::clone()
{
    Entity* e = new ConcreteProducer(*ec, size, xPosition, yPosition);
    return e;
}