#ifndef WOODPRODUCER_H
#define WOODPRODUCER_H

#include "entities/industry/base/Industry.h"

class WoodProducer : public Industry
{
public:
    WoodProducer(WoodProducer* WoodProducer);
    WoodProducer(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect,
                 int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~WoodProducer();
    void update();
    Entity *clone();
};

#endif // WOODPRODUCER_H
