#ifndef STONEPRODUCER_H
#define STONEPRODUCER_H

#include "entities/industry/base/Industry.h"
class StoneProducerLevelOneUpgrade;

class StoneProducer : public Industry
{
public:
    StoneProducer();
    StoneProducer(StoneProducer *stoneProducer);
    StoneProducer(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~StoneProducer();
    void update() override;
    Entity *clone() override;
    Entity *upgrade() override;
};

#endif // STONEPRODUCER_H
