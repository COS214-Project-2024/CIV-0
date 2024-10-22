#ifndef AIRPORT_H
#define AIRPORT_H

#include "Transport.h"

class Airport : public Transport
{
public:
    Airport();
    Airport(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Airport();
    void update(); //TODO
    Entity* clone();
};

#endif // AIRPORT_H
