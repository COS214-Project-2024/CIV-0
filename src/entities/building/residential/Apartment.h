#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"

class Apartment : public ResidentialBuilding
{
public:
    Apartment();
    Apartment(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Apartment();

    void update();
    Entity* clone();
};

#endif // APARTMENT_H
