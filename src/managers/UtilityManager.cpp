#include "UtilityManager.h"
#include "entities/utility/powerplant/PowerPlantLevelOneUpgrade.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelOneUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelThreeUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelOneUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelThreeUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelOneUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"

UtilityManager::UtilityManager() {

}

UtilityManager::~UtilityManager() {

}

void UtilityManager::buildUtility(EntityType type, Size size, int x, int y) {
    if(type != EntityType::POWERPLANT && type != EntityType::SEWAGESYSTEM && type != EntityType::WASTEMANAGMENT && type != EntityType::WATERSUPPLY) {
        return;
    }
    
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
        // Assuming CityManager has already checked that there is space - let me know if this assumption is wrong
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

int UtilityManager::getWasteProduction() {
    return City::instance()->getWasteProduction();
}

int UtilityManager::getWasteConsumption() {
    return City::instance()->getWasteConsumption();
}

int UtilityManager::getSewageProduction() {
    return City::instance()->getSewageProduction();
}

int UtilityManager::getSewageConsumption() {
    return City::instance()->getSewageConsumption();
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

std::vector<Utility*> UtilityManager::getAllWasteManagements() {
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
    Cost cost = utility->getCost();
    City* city = City::instance();

    if(cost.moneyCost <= city->getMoney() && cost.woodCost <= city->getWood() && cost.stoneCost <= city->getStone() && cost.concreteCost <= city->getConcrete()) {
        return true;
    } else {
        return false;
    }
}

bool UtilityManager::upgrade(Utility*& utility) {
    if (utility != nullptr && canAffordUpgrade(utility)) {
        Entity* upgradedUtility = utility->upgrade();

        // upgradedUtility returns nullptr if the utility is already at the maximum level
        if (upgradedUtility != nullptr) {
            std::vector<std::vector<Entity*>>& grid = City::instance()->getGrid();

            for (int i = utility->getXPosition(); i < utility->getXPosition() + utility->getWidth(); i++) {
                for (int j = utility->getYPosition() - utility->getHeight() + 1; j <= utility->getYPosition(); j++) {
                    grid[i][j] = upgradedUtility;
                }
            }

            delete utility;
            utility = (Utility*) upgradedUtility;

            // Subtract cost
            Cost cost = utility->getCost();
            City* city = City::instance();
            city->setMoney(city->getMoney() - cost.moneyCost);
            city->setWood(city->getWood() - cost.woodCost);
            city->setStone(city->getStone() - cost.stoneCost);
            city->setConcrete(city->getConcrete() - cost.concreteCost);

            return true;
        }
    }

    return false;
}