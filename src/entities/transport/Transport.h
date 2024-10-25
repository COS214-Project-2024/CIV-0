#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "entities/base/Entity.h"
#include "entities/building/residential/ResidentialBuilding.h"

class Transport : public Entity
{
public:
    Transport();
    Transport(EntityConfig ec, Size size, int xPos, int yPos);
    Transport(Transport* transport);
    virtual ~Transport();
    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // TRANSPORT_H
