#ifndef STONEPRODUCER_H
#define STONEPRODUCER_H

#include "entities/industry/base/Industry.h"

class StoneProducer : public Industry
{
public:
    StoneProducer();
    StoneProducer(StoneProducer *stoneProducer);
    StoneProducer(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~StoneProducer();
    void update();
    Entity *clone();
    virtual Entity* upgrade() = 0;
};

#endif // STONEPRODUCER_H
