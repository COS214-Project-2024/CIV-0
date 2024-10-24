#ifndef OFFICE_H
#define OFFICE_H

#include "EconomicBuilding.h"

class Office : public EconomicBuilding
{
public:
    Office();
    Office(EntityConfig ec, Size size, int xPos, int yPos);
    Office(Office* office);
    ~Office();

    void update();
    Entity* clone();
};

#endif // OFFICE_H
