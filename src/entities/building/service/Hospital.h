#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "ServiceBuilding.h"

class Hospital : public ServiceBuilding
{
public:
    Hospital();
    Hospital(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~Hospital();

    void update();
    Entity* clone();
};

#endif // HOSPITAL_H
