#ifndef POLICESTATION_H
#define POLICESTATION_H

#include "ServiceBuilding.h"

class PoliceStation : public ServiceBuilding
{
public:
    PoliceStation();
    PoliceStation(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~PoliceStation();

    void update();
    Entity* clone();
};

#endif // POLICESTATION_H
