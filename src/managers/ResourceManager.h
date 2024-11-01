#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "src/entities/industry/base/Industry.h"
#include "src/iterators/industry/ConcreteProducerIterator.h"
#include "src/iterators/industry/StoneProducerIterator.h"
#include "src/iterators/industry/IndustryIterator.h"
#include "src/iterators/industry/WoodProducerIterator.h"
#include "city/City.h"
#include "src/factory/industry/IndustryFactory.h"
#include "src/visitors/resource/ResourceVisitor.h"

class ResourceManager
{
public:

    ResourceManager();
    ~ResourceManager();
    void buildIndustry(EntityType type, Size size, int x, int y);
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
    bool upgrade(Industry*& industry);

};

#endif // RESOURCEMANAGER_H
