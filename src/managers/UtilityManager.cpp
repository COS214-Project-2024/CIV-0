#include "UtilityManager.h"

UtilityManager::UtilityManager() {

}

UtilityManager::~UtilityManager() {

}

void UtilityManager::buildUtility(EntityType type, Size size, int x, int y) {
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
        City::instance()->addEntity(utility);
    }
}

int UtilityManager::getElectricityProduction() {
    return City::instance()->getElectricityProduction();
}

int UtilityManager::getElectricityConsumption() {
    return City::instance()->getElectricityConsumption();
}

int UtilityManager::getWaterProduction() {
    return City::instance()->getWaterProduction();
}

int UtilityManager::getWaterConsumption() {
    return City::instance()->getWaterConsumption();
}

std::vector<Utility*> UtilityManager::getAllUtilities() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    UtilityIterator utilityIterator = UtilityIterator(grid);
    std::vector<Utility*> utilities = std::vector<Utility*>();

    utilityIterator.first();
    while (utilityIterator.hasNext()) {
        Utility* utility = dynamic_cast<Utility*>(utilityIterator.current());

        if (utility != nullptr) {
            utilities.push_back(utility);
        }

        utilityIterator.next();
    }

    return utilities;
}

std::vector<Utility*> UtilityManager::getAllWaterSupplies() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    WaterSupplyIterator waterSupplyIterator = WaterSupplyIterator(grid);
    std::vector<Utility*> waterSupplies = std::vector<Utility*>();

    waterSupplyIterator.first();
    while (waterSupplyIterator.hasNext()) {
        WaterSupply* waterSupply = dynamic_cast<WaterSupply*>(waterSupplyIterator.current());

        if (waterSupply != nullptr) {
            waterSupplies.push_back(waterSupply);
        }
        
        waterSupplyIterator.next();
    }

    return waterSupplies;
}

std::vector<Utility*> UtilityManager::getAllPowerPlants() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    PowerPlantIterator powerPlantIterator = PowerPlantIterator(grid);
    std::vector<Utility*> powerPlants = std::vector<Utility*>();

    powerPlantIterator.first();
    while (powerPlantIterator.hasNext()) {
        PowerPlant* powerPlant = dynamic_cast<PowerPlant*>(powerPlantIterator.current());

        if (powerPlant != nullptr) {
            powerPlants.push_back(powerPlant);
        }
        
        powerPlantIterator.next();
    }

    return powerPlants;
}

std::vector<Utility*> UtilityManager::getAllWasteManagement() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    WasteManagementIterator wasteManagementIterator = WasteManagementIterator(grid);
    std::vector<Utility*> wasteManagements = std::vector<Utility*>();

    wasteManagementIterator.first();
    while (wasteManagementIterator.hasNext()) {
        WasteManagement* wasteManagement = dynamic_cast<WasteManagement*>(wasteManagementIterator.current());

        if (wasteManagement != nullptr) {
            wasteManagements.push_back(wasteManagement);
        }
        
        wasteManagementIterator.next();
    }

    return wasteManagements;
}

std::vector<Utility*> UtilityManager::getAllSewageSystems() {
    std::vector<std::vector<Entity*>> grid = City::instance()->getGrid();
    SewageSystemIterator sewageSystemIterator = SewageSystemIterator(grid);
    std::vector<Utility*> sewageSystems = std::vector<Utility*>();

    sewageSystemIterator.first();
    while (sewageSystemIterator.hasNext()) {
        SewageSystem* sewageSystem = dynamic_cast<SewageSystem*>(sewageSystemIterator.current());

        if (sewageSystem != nullptr) {
            sewageSystems.push_back(sewageSystem);
        }
        
        sewageSystemIterator.next();
    }

    return sewageSystems;
}

bool UtilityManager::canAffordUpgrade(Utility* utility) {
    //return utility->canAffordUpgrade();
}

bool UtilityManager::upgrade(Utility* utility) {
    if(canAffordUpgrade(utility)) {
        //utility->upgrade();
    }
}