#ifndef CONCRETEPRODUCER_H
#define CONCRETEPRODUCER_H

#include "entities/industry/base/Industry.h"

class ConcreteProducer : public Industry
{
public:
    ConcreteProducer();
    ConcreteProducer(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~ConcreteProducer();

    void update();
    Entity* clone();
};

#endif // CONCRETEPRODUCER_H
