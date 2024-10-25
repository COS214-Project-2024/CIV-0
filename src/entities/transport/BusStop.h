#ifndef BUSSTOP_H
#define BUSSTOP_H

#include "Transport.h"

class BusStop : public Transport
{
public:
    BusStop();
    BusStop(EntityConfig ec, Size size, int xPos, int yPos);
    BusStop(BusStop* busStop);
    virtual ~BusStop();
    void update();
    Entity* clone();
};

#endif // BUSSTOP_H
