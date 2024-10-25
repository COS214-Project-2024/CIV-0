#ifndef TRANSPORTITERATOR_H
#define TRANSPORTITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/transport/Transport.h"

class TransportIterator : public Iterator
{
public:
    TransportIterator();
    ~TransportIterator();

    TransportIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity* current();
};

#endif // TRANSPORTITERATOR_H
