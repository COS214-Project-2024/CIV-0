#ifndef STONEPRODUCER_H
#define STONEPRODUCER_H

#include "entities/industry/base/Industry.h"

class StoneProducer : Industry
{
public:
    StoneProducer();
    StoneProducer(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~StoneProducer();
    void update();
    Entity* clone();
};

#endif // STONEPRODUCER_H
