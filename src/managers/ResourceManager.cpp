#include "src/managers/ResourceManager.h"

ResourceManager::ResourceManager() {}
ResourceManager::~ResourceManager() {}

std::vector<Industry*> ResourceManager::getAllConcreteProducers() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    ConcreteProducerIterator* iterator = new ConcreteProducerIterator(grid);  
    std::vector<Industry*> vectorFromDespicibleMe;

    for (iterator->first(); iterator->hasNext(); iterator->next()) {
        ConcreteProducer* producer = dynamic_cast<ConcreteProducer*>(iterator->current());
        if (producer) {
            vectorFromDespicibleMe.push_back(producer);
        }
    }

    delete iterator;
    return vectorFromDespicibleMe;
}

std::vector<Industry*> ResourceManager::getAllStoneProducers() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    StoneProducerIterator* iterator = new StoneProducerIterator(grid); 
    std::vector<Industry*> stoneProducers;

    for (iterator->first(); iterator->hasNext(); iterator->next()) {
        StoneProducer* producer = dynamic_cast<StoneProducer*>(iterator->current());
        if (producer) {
            stoneProducers.push_back(producer);
        }
    }

    delete iterator; 
    return stoneProducers;
}

std::vector<Industry*> ResourceManager::getAllWoodProducers() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    WoodProducerIterator* iterator = new WoodProducerIterator(grid);
    std::vector<Industry*> woodProducers;

    for (iterator->first(); iterator->hasNext(); iterator->next()) {
        WoodProducer* producer = dynamic_cast<WoodProducer*>(iterator->current());
        if (producer) {
            woodProducers.push_back(producer);
        }
    }

    delete iterator; 
    return woodProducers;
}


std::vector<Industry*> ResourceManager::getAllIndustryBuildings() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    IndustryIterator* iterator = new IndustryIterator(grid);
    std::vector<Industry*> industryBuildings;

    for (iterator->first(); iterator->hasNext(); iterator->next()) {
        Industry* building = dynamic_cast<Industry*>(iterator->current());
        if (building) {
            industryBuildings.push_back(building);
        }
    }

    delete iterator; 
    return industryBuildings;
}


bool ResourceManager::canAffordUpgrade(Industry* industry) {
    Cost cost = industry->getCost(); //this WILL break, do NOT use it yet
    City* city = City::instance();

    if(cost.moneyCost <= city->getMoney() && cost.woodCost <= city->getWood() && cost.stoneCost <= city->getStone() && cost.concreteCost <= city->getConcrete()) {
        return true;
    } else {
        return false;
    }
}


bool ResourceManager::upgrade(Industry*& industry) {
    if(industry != nullptr && canAffordUpgrade(industry)) {
        Entity* industryUpgrade = industry->upgrade();
    }
}