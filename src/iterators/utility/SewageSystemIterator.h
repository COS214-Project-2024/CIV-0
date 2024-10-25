#ifndef SEWAGESYSTEMITERATOR_H
#define SEWAGESYSTEMITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/utility/sewagesystem/SewageSystem.h"

class SewageSystemIterator : public Iterator{
public:
    SewageSystemIterator();
    ~SewageSystemIterator();

    SewageSystemIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity* current();
};

#endif // SEWAGESYSTEMITERATOR_H
