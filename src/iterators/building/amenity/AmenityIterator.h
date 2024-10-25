#ifndef AMENITYITERATOR_H
#define AMENITYITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/building/amenity/Amenity.h"

class AmenityIterator : public Iterator{
public:
    AmenityIterator();
    ~AmenityIterator();

    AmenityIterator(std::vector<std::vector<Entity*>> &grid);
     void first();
     void next();
     bool hasNext();
     Entity* current();
};

#endif // AMENITYITERATOR_H
