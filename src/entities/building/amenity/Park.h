#ifndef PARK_H
#define PARK_H

#include "Amenity.h"

class Park : public Amenity
{
public:
    Park();
    Park(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~Park();

    void update();
    Entity* clone();
};

#endif // PARK_H
