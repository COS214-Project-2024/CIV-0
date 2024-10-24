#ifndef THEATER_H
#define THEATER_H

#include "Amenity.h"

class Theater : public Amenity
{
public:
    Theater();
    Theater(EntityConfig ec, Size size, int xPos, int yPos);
    Theater(Theater* theater);
    ~Theater();

    void update();
    Entity* clone();
};

#endif // THEATER_H
