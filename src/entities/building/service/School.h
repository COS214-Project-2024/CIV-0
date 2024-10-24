#ifndef SCHOOL_H
#define SCHOOL_H

#include "ServiceBuilding.h"

class School : public ServiceBuilding
{
public:
    School();
    School(EntityConfig ec, Size size, int xPos, int yPos);
    School(School* school);
    ~School();

    void update();
    Entity* clone();
};

#endif // SCHOOL_H
