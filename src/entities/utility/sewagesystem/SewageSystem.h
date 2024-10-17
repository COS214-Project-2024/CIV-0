#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "entities/utility/base/Utility.h"

class SewageSystem : public Utility
{
public:
    SewageSystem();
    SewageSystem(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~SewageSystem();

    void update();
    Entity* clone();
};

#endif // SEWAGESYSTEM_H
