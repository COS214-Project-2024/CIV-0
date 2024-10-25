#ifndef CONCRETEPRODUCERITERATOR_H
#define CONCRETEPRODUCERITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/industry/concreteproducer/ConcreteProducer.h"

class ConcreteProducerIterator : public Iterator{
public:
    ConcreteProducerIterator();
    ~ConcreteProducerIterator();

    ConcreteProducerIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity* current();
};

#endif // CONCRETEPRODUCERITERATOR_H
