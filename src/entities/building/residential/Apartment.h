#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"

class Apartment : public ResidentialBuilding
{
public:
    Apartment();
    Apartment(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~Apartment();

    Entity* clone();
};

#endif // APARTMENT_H
