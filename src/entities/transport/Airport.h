#ifndef AIRPORT_H
#define AIRPORT_H

#include "Transport.h"

class Airport : public Transport
{
public:
    Airport();
    Airport(EntityConfig ec, Size size, int xPos, int yPos);
    Airport(Airport* airport);

    virtual ~Airport();
    void update(); //TODO
    Entity* clone();
};

#endif // AIRPORT_H
