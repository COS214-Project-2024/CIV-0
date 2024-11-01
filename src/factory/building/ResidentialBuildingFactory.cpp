
#include "ResidentialBuildingFactory.h"

ResidentialBuildingFactory::ResidentialBuildingFactory() {
}
ResidentialBuildingFactory::~ResidentialBuildingFactory() {
}

Entity* ResidentialBuildingFactory::createEntity(EntityType type, Size size, int xPos, int yPos) {
	switch (type) {
		case EntityType::HOUSE:
			return createHouse(size, xPos, yPos);
			break;
		case EntityType::APARTMENT:
			return createApartment(size, xPos, yPos);
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

