#include "BuildingManager.h"

#include "city/City.h"
#include "factory/building/EconomicBuildingFactory.h"
#include "factory/building/ResidentialBuildingFactory.h"

BuildingManager::BuildingManager() {}
BuildingManager::~BuildingManager() {}

bool BuildingManager::buildBuilding(EntityType type, Size size, int x, int y) {
	Entity *newBuilding = nullptr;
	if (type == EntityType::HOUSE || type == EntityType::APARTMENT) {
		ResidentialBuildingFactory *aFactory = new ResidentialBuildingFactory();
		newBuilding = aFactory->createEntity(type, size, x, y);
		delete aFactory;
	} else if (type == EntityType::FACTORY || type == EntityType::SHOPPINGMALL || type == EntityType::OFFICE) {
		EconomicBuildingFactory *eFactory = new EconomicBuildingFactory();
		newBuilding = eFactory->createEntity(type, size, x, y);
		delete eFactory;
	} else {
		return false;
	}
	if (newBuilding == nullptr) {
		return false;
	}
	City::instance()->addEntity(newBuilding);
	return true;
}