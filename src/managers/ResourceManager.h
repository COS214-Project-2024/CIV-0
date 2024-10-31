#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "src/entities/industry/base/Industry.h"
class ResourceManager
{
public:

    ResourceManager();
    ~ResourceManager();
    int calculateMoneyMade(); //ask richard how to get the money
    int calculateWoodMade();
    int calculateStoneMade();
    int calculateConcreteMade();
    
    std::vector<Industry*> getAllIndustryBuildings();
    std::vector<Industry*> getAllConcreteProducers();
    std::vector<Industry*> getAllStoneProducers();
    std::vector<Industry*> getAllWoodProducers();
    bool canAffordUpgrade(Industry* industry);
    bool canUpgrade(Industry* industry);
    bool upgrade(Industry* industry);

};

#endif // RESOURCEMANAGER_H
