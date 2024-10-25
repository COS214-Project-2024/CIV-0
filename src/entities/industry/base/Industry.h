#ifndef INDUSTRY_H
#define INDUSTRY_H

#include "entities/base/Entity.h"
#include "entities/building/residential/ResidentialBuilding.h"

class Industry : public Entity
{
private:
    int output;
public:
    Industry();
    Industry(EntityConfig ec, Size size, int xPos, int yPos);
    Industry(Industry* industry);
    virtual ~Industry();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
    int getOutput();
    void setOutput(int output);
};

#endif // INDUSTRY_H
