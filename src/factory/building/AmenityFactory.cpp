
#include "AmenityFactory.h"

AmenityFactory::AmenityFactory() {}
AmenityFactory::~AmenityFactory() {}

Entity* AmenityFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::PARK:
			return createPark(Size::SMALL, xPos, yPos);
			break;
		case EntityType::THEATER:
			return createTheater(Size::SMALL, xPos, yPos);
			break;
		case EntityType::MONUMENT:
			return createMonument(Size::SMALL, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* AmenityFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::PARK:
			return createPark(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::THEATER:
			return createTheater(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::MONUMENT:
			return createMonument(Size::MEDIUM, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* AmenityFactory::createLargeEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::PARK:
			return createPark(Size::LARGE, xPos, yPos);
			break;
		case EntityType::THEATER:
			return createTheater(Size::LARGE, xPos, yPos);
			break;
		case EntityType::MONUMENT:
			return createMonument(Size::LARGE, xPos, yPos);
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
