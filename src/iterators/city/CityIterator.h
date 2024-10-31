#ifndef CITYITERATOR_H
#define CITYITERATOR_H

#include "iterators/base/Iterator.h"
#include "city/City.h"

class CityIterator : public Iterator
{
private:
    bool unique;

public:
    CityIterator();
    ~CityIterator();

    // Constructor with unique iteration option
    CityIterator(std::vector<std::vector<Entity *>> &grid, bool unique = true);

    void first() override;
    void next() override;
    bool hasNext() override;
    Entity *current() override;
};

#endif // CITYITERATOR_H
