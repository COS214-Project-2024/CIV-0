#ifndef INDUSTRYITERATOR_H
#define INDUSTRYITERATOR_H

#include "iterators/base/Iterator.h"
#include "entities/industry/base/Industry.h"

class IndustryIterator : public Iterator
{
public:
    IndustryIterator();
    ~IndustryIterator();

    IndustryIterator(std::vector<std::vector<Entity *>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity *current();
};

#endif // INDUSTRYITERATOR_H