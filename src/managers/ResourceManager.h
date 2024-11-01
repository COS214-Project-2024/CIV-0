#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "entities/industry/base/Industry.h"
#include "iterators/industry/ConcreteProducerIterator.h"
#include "iterators/industry/StoneProducerIterator.h"
#include "iterators/industry/IndustryIterator.h"
#include "iterators/industry/WoodProducerIterator.h"
#include "city/City.h"
#include "factory/industry/IndustryFactory.h"
#include "visitors/resource/ResourceVisitor.h"
#include "visitors/tax/TaxCalculationVisitor.h"

class ResourceManager
{
public:

    ResourceManager();
    ~ResourceManager();
    void buildIndustry(EntityType type, Size size, int x, int y);
    int calculateMoneyMade();
    int calculateWoodMade();
    int calculateStoneMade();
    int calculateConcreteMade();
    
    std::vector<Industry*> getAllIndustryBuildings();
    std::vector<Industry*> getAllConcreteProducers();
    std::vector<Industry*> getAllStoneProducers();
    std::vector<Industry*> getAllWoodProducers();
    bool canAffordUpgrade(Industry* industry);
    // bool canUpgrade(Industry* industry);
    bool upgrade(Industry*& industry);

};

#endif // RESOURCEMANAGER_H
