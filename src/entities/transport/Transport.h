#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"
#include "entities/building/residential/ResidentialBuilding.h"

class Transport : public Entity, public Subject
{
public:
    Transport();
    Transport(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Transport();
    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // TRANSPORT_H
