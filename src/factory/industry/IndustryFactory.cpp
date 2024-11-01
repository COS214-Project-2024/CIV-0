#include "IndustryFactory.h"

IndustryFactory::IndustryFactory() {}
IndustryFactory::~IndustryFactory() {}
Entity* IndustryFactory::createEntity(EntityType type, Size size, int xPos, int yPos) {
	switch (type) {
		case EntityType::CONCRETEPRODUCER:
			return createConcreteProducer(size, xPos, yPos);
			break;
		case EntityType::STONEPRODUCER:
			return createStoneProducer(size, xPos, yPos);
			break;
		case EntityType::WOODPRODUCER:
			return createWoodProducer(size, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* IndustryFactory::createConcreteProducer(Size size, int xPos, int yPos) {
	return new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, size), size, xPos, yPos);
}

Entity* IndustryFactory::createStoneProducer(Size size, int xPos, int yPos) {
	return new StoneProducer(ConfigManager::getEntityConfig(EntityType::STONEPRODUCER, size), size, xPos, yPos);
}

Entity* IndustryFactory::createWoodProducer(Size size, int xPos, int yPos) {
	return new WoodProducer(ConfigManager::getEntityConfig(EntityType::WOODPRODUCER, size), size, xPos, yPos);
}