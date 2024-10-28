#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

#include "iterators/base/Iterator.h"
#include "entities/building/base/Building.h"

class BuildingIterator : public Iterator
{
public:
    BuildingIterator();
    ~BuildingIterator();

    BuildingIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity* current();
};

#endif // BUILDINGITERATOR_H
