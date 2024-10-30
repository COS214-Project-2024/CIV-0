#ifndef STONEPRODUCERITERATOR_H
#define STONEPRODUCERITERATOR_H

#include "iterators/base/Iterator.h"
#include "entities/industry/stoneproducer/StoneProducer.h"

class StoneProducerIterator : public Iterator
{
public:
    StoneProducerIterator();
    ~StoneProducerIterator();

    StoneProducerIterator(std::vector<std::vector<Entity *>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity *current();
};

#endif // STONEPRODUCERITERATOR_H
