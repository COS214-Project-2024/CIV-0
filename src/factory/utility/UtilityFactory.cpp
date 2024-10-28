
#include "UtilityFactory.h"

UtilityFactory::UtilityFactory() {
}
UtilityFactory::~UtilityFactory()
{
}

Entity* UtilityFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::POWERPLANT:
			return createPowerPlant(Size::SMALL, xPos, yPos);
			break;
		case EntityType::WATERSUPPLY:
			return createWaterSupply(Size::SMALL, xPos, yPos);
			break;
		case EntityType::WASTEMANAGMENT:
			return createWasteManagement(Size::SMALL, xPos, yPos);
			break;
		case EntityType::SEWAGESYSTEM:
			return createSewageSystem(Size::SMALL, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* UtilityFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::POWERPLANT:
			return createPowerPlant(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::WATERSUPPLY:
			return createWaterSupply(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::WASTEMANAGMENT:
			return createWasteManagement(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::SEWAGESYSTEM:
			return createSewageSystem(Size::MEDIUM, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* UtilityFactory::createLargeEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::POWERPLANT:
			return createPowerPlant(Size::LARGE, xPos, yPos);
			break;
		case EntityType::WATERSUPPLY:
			return createWaterSupply(Size::LARGE, xPos, yPos);
			break;
		case EntityType::WASTEMANAGMENT:
			return createWasteManagement(Size::LARGE, xPos, yPos);
			break;
		case EntityType::SEWAGESYSTEM:
			return createSewageSystem(Size::LARGE, xPos, yPos);
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
	return new WasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, size), size, xPos, yPos);
}

Entity* UtilityFactory::createSewageSystem(Size size, int xPos, int yPos) {
	return new SewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, size), size, xPos, yPos);
}
