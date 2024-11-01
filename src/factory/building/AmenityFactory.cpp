
#include "AmenityFactory.h"

AmenityFactory::AmenityFactory() {}
AmenityFactory::~AmenityFactory() {}

Entity* AmenityFactory::createEntity(EntityType type,Size size, int xPos, int yPos) {
	switch (type) {
		case EntityType::PARK:
			return createPark(size, xPos, yPos);
			break;
		case EntityType::THEATER:
			return createTheater(size, xPos, yPos);
			break;
		case EntityType::MONUMENT:
			return createMonument(size, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}


Entity* AmenityFactory::createPark(Size size, int xPos, int yPos) {
	return new Park(ConfigManager::getEntityConfig(EntityType::PARK, size), size, xPos, yPos);
}

Entity* AmenityFactory::createTheater(Size size, int xPos, int yPos) {
	return new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, size), size, xPos, yPos);
}

Entity* AmenityFactory::createMonument(Size size, int xPos, int yPos) {
	return new Monument(ConfigManager::getEntityConfig(EntityType::MONUMENT, size), size, xPos, yPos);
}
