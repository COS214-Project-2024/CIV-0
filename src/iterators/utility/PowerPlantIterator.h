#ifndef POWERPLANTITERATOR_H
#define POWERPLANTITERATOR_H

#include "iterators/base/Iterator.h"
#include "../entities/utility/powerplant/PowerPlant.h"

class PowerPlantIterator : public Iterator
{
public:
    PowerPlantIterator();
    ~PowerPlantIterator();
    
    PowerPlantIterator(std::vector<std::vector<Entity*>> &grid);
    void first();
    void next();
    bool hasNext();
    Entity* current();
};

#endif // POWERPLANTITERATOR_H
