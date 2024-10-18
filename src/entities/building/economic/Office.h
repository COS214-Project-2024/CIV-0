#ifndef OFFICE_H
#define OFFICE_H

#include "EconomicBuilding.h"

class Office : public EconomicBuilding
{
public:
    Office();
    Office(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Office();

    void update();
    Entity* clone();
};

#endif // OFFICE_H
