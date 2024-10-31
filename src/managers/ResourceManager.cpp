#include "ResourceManager.h"

ResourceManager::ResourceManager() {}
ResourceManager::~ResourceManager() {}

void ResourceManager::upgrade(Industry* industry) {
    industry->update();
}

std::vector<Industry*> ResourceManager::getAllConcreteProducers() {
    ConcreteProducerIterator* iterator = new ConcreteProducerIterator();
    std::vector<Industry*> vectorFromDespicibleMe;
    iterator->first();

    while(iterator->hasNext()) {
        ConcreteProducer* producer = dynamic_cast<ConcreteProducer*>(iterator->current());
        if(producer) {
            vectorFromDespicibleMe.push_back(producer);
        }
        iterator->next();
    }

    ConcreteProducer* last = dynamic_cast<ConcreteProducer*>(iterator->current());
    if(last) {
        vectorFromDespicibleMe.push_back(last);
    }

    delete iterator;
    return vectorFromDespicibleMe;
}