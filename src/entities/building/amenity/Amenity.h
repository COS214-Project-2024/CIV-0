#ifndef AMENITY_H
#define AMENITY_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"
#include "entities/building/residential/ResidentialBuilding.h"

class Amenity : public Building, public Subject
{
public:
    Amenity();
    Amenity(EntityConfig ec, Size size, int xPos, int yPos);
    Amenity(Amenity* amenity);
    virtual ~Amenity();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
};

#endif // AMENITY_H
