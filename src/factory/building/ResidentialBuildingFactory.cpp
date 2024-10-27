
#include "ResidentialBuildingFactory.h"

ResidentialBuildingFactory::ResidentialBuildingFactory() {
}
ResidentialBuildingFactory::~ResidentialBuildingFactory() {
}

Entity* ResidentialBuildingFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::HOUSE:
			return createHouse(Size::SMALL, xPos, yPos);
			break;
		case EntityType::APARTMENT:
			return createApartment(Size::SMALL, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* ResidentialBuildingFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::HOUSE:
			return createHouse(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::APARTMENT:
			return createApartment(Size::MEDIUM, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* ResidentialBuildingFactory::createLargeEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::HOUSE:
			return createHouse(Size::LARGE, xPos, yPos);
			break;
		case EntityType::APARTMENT:
			return createApartment(Size::LARGE, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* ResidentialBuildingFactory::createHouse(Size size, int xPos, int yPos) {
	return new House(ConfigManager::getEntityConfig(EntityType::HOUSE, size), size, xPos, yPos);
}

Entity* ResidentialBuildingFactory::createApartment(Size size, int xPos, int yPos) {
	return new Apartment(ConfigManager::getEntityConfig(EntityType::APARTMENT, size), size, xPos, yPos);
}

