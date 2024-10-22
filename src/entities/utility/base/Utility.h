#ifndef UTILITY_H
#define UTILITY_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"
#include "entities/building/residential/ResidentialBuilding.h"

class Utility : public Entity, public Subject
{
private:
    int output;
public:
    Utility();
    Utility(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~Utility();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
    int getOutput();
    void setOutput(int output);
};

#endif // UTILITY_H
