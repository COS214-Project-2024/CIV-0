#ifndef RESIDENTIALBUILDINGITERATOR_H
#define RESIDENTIALBUILDINGITERATOR_H

#include "iterators/base/Iterator.h"
#include "entities/building/residential/ResidentialBuilding.h"

class ResidentialBuildingIterator : public Iterator
{
public:
    ResidentialBuildingIterator();
    ~ResidentialBuildingIterator();

    ResidentialBuildingIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
     void next();
     bool hasNext();
     Entity* current();
};

#endif // RESIDENTIALBUILDINGITERATOR_H
