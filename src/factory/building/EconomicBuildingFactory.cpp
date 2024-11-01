#include "EconomicBuildingFactory.h"

EconomicBuildingFactory::EconomicBuildingFactory() {}
EconomicBuildingFactory::~EconomicBuildingFactory() {}

Entity* EconomicBuildingFactory::createEntity(EntityType type, Size size, int xPos, int yPos) {
	switch (type) {
		case EntityType::FACTORY:
			return createFactory(size, xPos, yPos);
			break;
		case EntityType::SHOPPINGMALL:
			return createShoppingMall(size, xPos, yPos);
			break;
		case EntityType::OFFICE:
			return createOffice(size, xPos, yPos);
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
Entity* EconomicBuildingFactory::createOffice(Size size, int xPos, int yPos) {
	return new Office(ConfigManager::getEntityConfig(EntityType::OFFICE, size), size, xPos, yPos);
}
