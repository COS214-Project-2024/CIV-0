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
            utility->~Utility();

            // Use dynamic_cast to determine the specific type of upgradedUtility
            if (PowerPlantLevelOneUpgrade* powerPlantUpgrade = dynamic_cast<PowerPlantLevelOneUpgrade*>(upgradedUtility)) {
                utility = new (utility) PowerPlantLevelOneUpgrade(powerPlantUpgrade);
            } else if (auto* powerPlantUpgrade = dynamic_cast<PowerPlantLevelTwoUpgrade*>(upgradedUtility)) {
                utility = new (utility) PowerPlantLevelTwoUpgrade(powerPlantUpgrade);
            } else if (auto* powerPlantUpgrade = dynamic_cast<PowerPlantLevelThreeUpgrade*>(upgradedUtility)) {
                utility = new (utility) PowerPlantLevelThreeUpgrade(powerPlantUpgrade);
            } else if (auto* waterSupplyUpgrade = dynamic_cast<WaterSupplyLevelOneUpgrade*>(upgradedUtility)) {
                utility = new (utility) WaterSupplyLevelOneUpgrade(waterSupplyUpgrade);
            } else if (auto* waterSupplyUpgrade = dynamic_cast<WaterSupplyLevelTwoUpgrade*>(upgradedUtility)) {
                utility = new (utility) WaterSupplyLevelTwoUpgrade(waterSupplyUpgrade);
            } else if (auto* waterSupplyUpgrade = dynamic_cast<WaterSupplyLevelThreeUpgrade*>(upgradedUtility)) {
                utility = new (utility) WaterSupplyLevelThreeUpgrade(waterSupplyUpgrade);
            } else if (auto* wasteManagementUpgrade = dynamic_cast<WasteManagementLevelOneUpgrade*>(upgradedUtility)) {
                utility = new (utility) WasteManagementLevelOneUpgrade(wasteManagementUpgrade);
            } else if (auto* wasteManagementUpgrade = dynamic_cast<WasteManagementLevelTwoUpgrade*>(upgradedUtility)) {
                utility = new (utility) WasteManagementLevelTwoUpgrade(wasteManagementUpgrade);
            } else if (auto* wasteManagementUpgrade = dynamic_cast<WasteManagementLevelThreeUpgrade*>(upgradedUtility)) {
                utility = new (utility) WasteManagementLevelThreeUpgrade(wasteManagementUpgrade);
            } else if (auto* sewageSystemUpgrade = dynamic_cast<SewageSystemLevelOneUpgrade*>(upgradedUtility)) {
                utility = new (utility) SewageSystemLevelOneUpgrade(sewageSystemUpgrade);
            } else if (auto* sewageSystemUpgrade = dynamic_cast<SewageSystemLevelTwoUpgrade*>(upgradedUtility)) {
                utility = new (utility) SewageSystemLevelTwoUpgrade(sewageSystemUpgrade);
            } else if (auto* sewageSystemUpgrade = dynamic_cast<SewageSystemLevelThreeUpgrade*>(upgradedUtility)) {
                utility = new (utility) SewageSystemLevelThreeUpgrade(sewageSystemUpgrade);
            } else {
                return false;
            }

            delete upgradedUtility;

            // Subtract cost?

            return true;
        }
    }

    return false;
}