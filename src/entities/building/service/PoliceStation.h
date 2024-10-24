#ifndef POLICESTATION_H
#define POLICESTATION_H

#include "ServiceBuilding.h"

class PoliceStation : public ServiceBuilding
{
public:
    PoliceStation();
    PoliceStation(EntityConfig ec, Size size, int xPos, int yPos);
    PoliceStation(PoliceStation* police);
    ~PoliceStation();

    void update();
    Entity* clone();
};

#endif // POLICESTATION_H
