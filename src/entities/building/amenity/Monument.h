#ifndef MONUMENT_H
#define MONUMENT_H

#include "Amenity.h"

class Monument : public Amenity
{
public:
    Monument();
    Monument(EntityConfig ec, Size size, int xPos, int yPos);
    Monument(Monument* monument);

    virtual ~Monument();

    void update();
    Entity* clone();
};

#endif // MONUMENT_H
