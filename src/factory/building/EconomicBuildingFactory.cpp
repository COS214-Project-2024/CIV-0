#include "EconomicBuildingFactory.h"

EconomicBuildingFactory::EconomicBuildingFactory() {}
EconomicBuildingFactory::~EconomicBuildingFactory() {}

Entity* EconomicBuildingFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::FACTORY:
			return createFactory(Size::SMALL, xPos, yPos);
			break;
		case EntityType::SHOPPINGMALL:
			return createShoppingMall(Size::SMALL, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* EconomicBuildingFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::FACTORY:
			return createFactory(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::SHOPPINGMALL:
			return createShoppingMall(Size::MEDIUM, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* EconomicBuildingFactory::createLargeEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::FACTORY:
			return createFactory(Size::LARGE, xPos, yPos);
			break;
		case EntityType::SHOPPINGMALL:
			return createShoppingMall(Size::LARGE, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* EconomicBuildingFactory::createFactory(Size size, int xPos, int yPos) {
    return new Factory(ConfigManager::getEntityConfig(EntityType::FACTORY, size), size, xPos, yPos);
}

Entity* EconomicBuildingFactory::createShoppingMall(Size size, int xPos, int yPos) {
    return new ShoppingMall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, size), size, xPos, yPos);
}
