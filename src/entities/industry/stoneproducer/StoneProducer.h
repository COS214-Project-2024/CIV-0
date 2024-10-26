#ifndef STONEPRODUCER_H
#define STONEPRODUCER_H

#include "entities/industry/base/Industry.h"

class StoneProducer : Industry
{
public:
    StoneProducer();
    StoneProducer(EntityConfig ec, Size size, int xPos, int yPos);
    StoneProducer(StoneProducer* stoneProducer);
    virtual ~StoneProducer();

    void update();
    Entity* clone();
};

#endif // STONEPRODUCER_H
