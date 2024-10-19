#ifndef WASTEMANAGEMENTITERATOR_H
#define WASTEMANAGEMENTITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/utility/wastemanagement/WasteManagement.h"

class WasteManagementIterator : public Iterator{
public:
    WasteManagementIterator();
    ~WasteManagementIterator();

    WasteManagementIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    WasteManagement* current();
};

#endif // WASTEMANAGEMENTITERATOR_H
