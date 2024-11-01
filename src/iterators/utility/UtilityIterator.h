#ifndef UTILITYITERATOR_H
#define UTILITYITERATOR_H

#include "iterators/base/Iterator.h"
#include "entities/utility/base/Utility.h"

class UtilityIterator : public Iterator
{
public:
    UtilityIterator();
    ~UtilityIterator();

    UtilityIterator(std::vector<std::vector<Entity *>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity *current();
};

#endif // UTILITYITERATOR_H
