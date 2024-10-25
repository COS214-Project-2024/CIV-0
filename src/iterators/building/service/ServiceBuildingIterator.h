#ifndef SERVICEBUILDINGITERATOR_H
#define SERVICEBUILDINGITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/building/service/ServiceBuilding.h"

class ServiceBuildingIterator : public Iterator{
public:
    ServiceBuildingIterator();
    ~ServiceBuildingIterator();

    ServiceBuildingIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity* current();
};

#endif // SERVICEBUILDINGITERATOR_H
