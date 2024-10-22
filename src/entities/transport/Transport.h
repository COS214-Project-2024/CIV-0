#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"
#include "entities/building/residential/ResidentialBuilding.h"

class Transport : public Entity, public Subject
{
public:
    Transport();
    Transport(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~Transport();
    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // TRANSPORT_H
