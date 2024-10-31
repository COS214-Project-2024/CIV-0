#include "src/managers/ResourceManager.h"

ResourceManager::ResourceManager() {}
ResourceManager::~ResourceManager() {}

void ResourceManager::upgrade(Industry* industry) {
    industry->update();
}

std::vector<Industry*> ResourceManager::getAllConcreteProducers() {
    ConcreteProducerIterator* iterator = new ConcreteProducerIterator(); //dont forget to pass in the grid later 
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
    StoneProducerIterator* iterator = new StoneProducerIterator(); //same dealio here 
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
    WoodProducerIterator* iterator = new WoodProducerIterator();
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
    IndustryIterator* iterator = new IndustryIterator();
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


