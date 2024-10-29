#include "UtilityManager.h"

UtilityManager::UtilityManager() {

}

UtilityManager::~UtilityManager() {

}

void UtilityManager::buildUtility(EntityType type, Size size, int x, int y) {
    City* c = City::instance();
    UtilityFactory utilityFactory = UtilityFactory();
    Utility* utility = nullptr;

   if(size == Size::SMALL) {
        utility = dynamic_cast<Utility*>(utilityFactory.createSmallEntity(type, x, y));
    } else if (size == Size::MEDIUM) {
        utility = dynamic_cast<Utility*>(utilityFactory.createMediumEntity(type, x, y));
    } else {
        utility = dynamic_cast<Utility*>(utilityFactory.createLargeEntity(type, x, y));
    }

    if(utility != nullptr) {
        c->addEntity(utility);
    }
}

int UtilityManager::getElectricityProduction() {
    City* c = City::instance();
    return c->getElectricityConsumption();
}

int UtilityManager::getElectricityConsumption() {
    City* c = City::instance();
}

int UtilityManager::getWaterProduction() {
    City* c = City::instance();
}

int UtilityManager::getWaterConsumption() {
    City* c = City::instance();
}

std::vector<Utility*> UtilityManager::getAllUtilities() {
    City* c = City::instance();
}

std::vector<Utility*> UtilityManager::getAllWaterSupplies() {
    City* c = City::instance();
}

std::vector<Utility*> UtilityManager::getAllPowerPlants() {
    City* c = City::instance();
}

std::vector<Utility*> UtilityManager::getAllWasteManagement() {
    City* c = City::instance();
}

std::vector<Utility*> UtilityManager::getAllSewageSystems() {
    City* c = City::instance();
}

bool UtilityManager::canAffordUpgrade(Utility* utility) {
    City* c = City::instance();
}

bool UtilityManager::upgrade(Utility* utility) {
    City* c = City::instance();
}