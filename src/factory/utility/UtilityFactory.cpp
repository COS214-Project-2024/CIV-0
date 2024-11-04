
#include "UtilityFactory.h"

UtilityFactory::UtilityFactory() {
}
UtilityFactory::~UtilityFactory()
{
}

Entity* UtilityFactory::createEntity(EntityType type,Size size, int xPos, int yPos) {
	switch (type) {
		case EntityType::POWERPLANT:
			return createPowerPlant(size, xPos, yPos);
			break;
		case EntityType::WATERSUPPLY:
			return createWaterSupply(size, xPos, yPos);
			break;
		case EntityType::WASTEMANAGEMENT:
			return createWasteManagement(size, xPos, yPos);
			break;
		case EntityType::SEWAGESYSTEM:
			return createSewageSystem(size, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* UtilityFactory::createPowerPlant(Size size, int xPos, int yPos) {
	return new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, size), size, xPos, yPos);
}

Entity* UtilityFactory::createWaterSupply(Size size, int xPos, int yPos) {
	return new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, size), size, xPos, yPos);
}

Entity* UtilityFactory::createWasteManagement(Size size, int xPos, int yPos) {
	return new WasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, size), size, xPos, yPos);
}

Entity* UtilityFactory::createSewageSystem(Size size, int xPos, int yPos) {
	return new SewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, size), size, xPos, yPos);
}
