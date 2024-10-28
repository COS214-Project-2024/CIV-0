#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include "visitors/population/PopulationVisitor.h"
#include "visitors/satisfaction/SatisfactionVisitor.h"
#include "visitors/utility/UtilityVisitor.h"
#include "city/City.h"

class PopulationManager
{
private:
    int minimumIncrease;
    int maximumIncrease;
public:
    PopulationManager(int minimumIncrease, int maximumIncrease);
    ~PopulationManager();
    void calculatePopulationCapacity();
    void growPopulation();
    void decreasePopulation();
    void calculateSatisfaction();
};

#endif // POPULATIONMANAGER_H
