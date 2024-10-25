#ifndef WOODPRODUCERITERATOR_H
#define WOODPRODUCERITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/industry/woodproducer/WoodProducer.h"

class WoodProducerIterator : public Iterator{
public:
    WoodProducerIterator();
    ~WoodProducerIterator();

    WoodProducerIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity* current();
};

#endif // WOODPRODUCERITERATOR_H
