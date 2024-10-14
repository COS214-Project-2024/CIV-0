#ifndef AMENITY_H
#define AMENITY_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"

class Amenity : public Building, public Subject
{
public:
    Amenity();
    ~Amenity();
};

#endif // AMENITY_H
