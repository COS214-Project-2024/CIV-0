#ifndef INDUSTRY_H
#define INDUSTRY_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"

class Industry : public Entity, public Subject
{
private:
    int output;
public:
    Industry();
    Industry(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Industry();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
    int getOutput();
    void setOutput(int output);
};

#endif // INDUSTRY_H
