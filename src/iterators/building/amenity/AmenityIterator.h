#ifndef AMENITYITERATOR_H
#define AMENITYITERATOR_H

#include "iterators/base/Iterator.h"
#include "entities/building/amenity/Amenity.h"

class AmenityIterator : public Iterator
{
public:
    AmenityIterator();
    ~AmenityIterator();

    AmenityIterator(std::vector<std::vector<Entity *>> &grid);
    void first() override;
    void next() override;
    bool hasNext() override;
    Entity *current() override;
};

#endif // AMENITYITERATOR_H
