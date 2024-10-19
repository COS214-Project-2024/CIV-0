#ifndef UTILITY_H
#define UTILITY_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"

class Utility : public Entity, public Subject
{
private:
    int output;
public:
    Utility();
    Utility(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Utility();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
    int getOutput();
    void setOutput(int output);
};

#endif // UTILITY_H
