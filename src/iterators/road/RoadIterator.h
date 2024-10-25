#ifndef ROADITERATOR_H
#define ROADITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/road/Road.h"

class RoadIterator : public Iterator
{
public:
    RoadIterator();
    ~RoadIterator();

    RoadIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity* current();
};

#endif // ROADITERATOR_H
