#ifndef SCHOOL_H
#define SCHOOL_H

#include "ServiceBuilding.h"

class School : public ServiceBuilding
{
public:
    School();
    School(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~School();

    void update();
    Entity* clone();
};

#endif // SCHOOL_H
