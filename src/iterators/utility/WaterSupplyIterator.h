#ifndef WATERSUPPLYITERATOR_H
#define WATERSUPPLYITERATOR_H

#include "iterators/base/Iterator.h"
#include "entities/utility/watersupply/WaterSupply.h"

class WaterSupplyIterator : public Iterator
{
public:
    WaterSupplyIterator();
    ~WaterSupplyIterator();

    WaterSupplyIterator(std::vector<std::vector<Entity *>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity *current();
};

#endif // WATERSUPPLYITERATOR_H
