#ifndef CITYITERATOR_H
#define CITYITERATOR_H

#include "iterators/base/Iterator.h"
#include "city/City.h"

class CityIterator : public Iterator
{
public:
    CityIterator();
    ~CityIterator();

    CityIterator(std::vector<std::vector<Entity *>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity *current();
};

#endif // CITYITERATOR_H
