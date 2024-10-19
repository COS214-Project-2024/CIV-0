#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "ServiceBuilding.h"

class Hospital : public ServiceBuilding
{
public:
    Hospital();
    Hospital(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Hospital();

    void update();
    Entity* clone();
};

#endif // HOSPITAL_H
