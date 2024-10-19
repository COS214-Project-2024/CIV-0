#ifndef BUSSTOP_H
#define BUSSTOP_H

#include "Transport.h"

class BusStop : public Transport
{
public:
    BusStop();
    BusStop(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    ~BusStop();
    void update(); //TODO
    Entity* clone();
};

#endif // BUSSTOP_H
