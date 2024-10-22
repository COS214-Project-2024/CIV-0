#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "entities/utility/base/Utility.h"

class SewageSystem : public Utility
{
public:
    SewageSystem();
    SewageSystem(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~SewageSystem();

    void update();
    Entity* clone();
};

#endif // SEWAGESYSTEM_H
