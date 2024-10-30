#ifndef ECONOMICBUILDINGITERATOR_H
#define ECONOMICBUILDINGITERATOR_H

#include "iterators/base/Iterator.h"
#include "entities/building/economic/EconomicBuilding.h"

class EconomicBuildingIterator : public Iterator
{
public:
    EconomicBuildingIterator();
    ~EconomicBuildingIterator();

    EconomicBuildingIterator(std::vector<std::vector<Entity *>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity *current();
};

#endif // ECONOMICBUILDINGITERATOR_H
