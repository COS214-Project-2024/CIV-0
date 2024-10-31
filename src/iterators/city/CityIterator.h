#ifndef CITYITERATOR_H
#define CITYITERATOR_H

#include "iterators/base/Iterator.h"

class CityIterator : public Iterator
{
public:
    // Default constructor with iterateUnique set to true
    CityIterator(std::vector<std::vector<Entity *>> &grid);

    // Constructor with option to specify uniqueness
    CityIterator(std::vector<std::vector<Entity *>> &grid, bool iterateUnique);

    ~CityIterator();

    void first() override;
    void next() override;
    bool hasNext() override;
    Entity *current() override;

private:
    bool iterateUnique; // Determines if we should iterate over unique entities only
};

#endif // CITYITERATOR_H
