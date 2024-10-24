#ifndef WOODPRODUCER_H
#define WOODPRODUCER_H

#include "entities/industry/base/Industry.h"

class WoodProducer : public Industry
{
public:
    WoodProducer();
    WoodProducer(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~WoodProducer();

    void update();
    Entity* clone();
};

#endif // WOODPRODUCER_H
