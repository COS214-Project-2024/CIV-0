#include "UtilityManager.h"

#include "city/City.h"
#include "entities/utility/powerplant/PowerPlantLevelOneUpgrade.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelOneUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelOneUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelThreeUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelOneUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelThreeUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"
#include "visitors/population/PopulationVisitor.h"
#include "visitors/utility/UtilityVisitor.h"

UtilityManager::UtilityManager() {
}

UtilityManager::~UtilityManager() {
}

bool UtilityManager::buildUtility(EntityType type, Size size, int x, int y) {
	if (type != EntityType::POWERPLANT && type != EntityType::SEWAGESYSTEM && type != EntityType::WASTEMANAGMENT && type != EntityType::WATERSUPPLY) {
		return false;
	}

	UtilityFactory* utilityFactory = new UtilityFactory();
	Entity* utility = nullptr;
	utility = utilityFactory->createEntity(type, size, x, y);
	City::instance()->addEntity(utility);
	delete utilityFactory;
	return true;
}

int UtilityManager::getElectricityProduction() {
	UtilityVisitor uv;
	uv.visit(City::instance());
	City::instance()->setElectricityProduction(uv.getTotalElectricity());
	return City::instance()->getElectricityProduction();
}

int UtilityManager::getElectricityConsumption() {
	PopulationVisitor uv;
	uv.visit(City::instance());
	City::instance()->setElectricityConsumption(uv.getTotalElectricityConsumption());
	return City::instance()->getElectricityConsumption();
}

int UtilityManager::getWaterProduction() {
	UtilityVisitor uv;
	uv.visit(City::instance());
	City::instance()->setWaterProduction(uv.getTotalWater());
	return City::instance()->getWaterProduction();
}

int UtilityManager::getWaterConsumption() {
	PopulationVisitor uv;
	uv.visit(City::instance());
	City::instance()->setWaterConsumption(uv.getTotalWaterConsumption());
	return City::instance()->getWaterConsumption();
}

int UtilityManager::getWasteProduction() {
	UtilityVisitor uv;
	uv.visit(City::instance());
	City::instance()->setWasteProduction(uv.getTotalWasteHandled());
	return City::instance()->getWasteProduction();
}

// NOT IMPLEMENTED - ENTITY HAS NO WASTE ATTRIBUTE - WasteConsumption = WasteProduction for the moment
int UtilityManager::getWasteConsumption() {
	UtilityVisitor uv;
	uv.visit(City::instance());
	City::instance()->setWasteConsumption(uv.getTotalWasteHandled());
	return City::instance()->getWasteConsumption();
}

int UtilityManager::getSewageProduction() {
	UtilityVisitor uv;
	uv.visit(City::instance());
	City::instance()->setSewageProduction(uv.getTotalSewageHandled());
	return City::instance()->getSewageProduction();
}

// NOT IMPLEMENTED - ENTITY HAS NO SEWAGE ATTRIBUTE - SewageConsumption = SewageProduction for the moment
int UtilityManager::getSewageConsumption() {
	UtilityVisitor uv;
	uv.visit(City::instance());
	City::instance()->setSewageConsumption(uv.getTotalSewageHandled());
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

	if (cost.moneyCost <= city->getMoney() && cost.woodCost <= city->getWood() && cost.stoneCost <= city->getStone() && cost.concreteCost <= city->getConcrete()) {
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
			utility = (Utility*)upgradedUtility;

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