#ifndef STONEPRODUCER_H
#define STONEPRODUCER_H

#include "entities/industry/base/Industry.h"

class StoneProducer : public public Industry
{
public:
    StoneProducer();
    StoneProducer(StoneProducer* stoneProd);
    StoneProducer(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~StoneProducer();
    void update();
    Entity *clone();
};

#endif // STONEPRODUCER_H
