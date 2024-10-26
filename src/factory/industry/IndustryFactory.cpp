#include "IndustryFactory.h"

IndustryFactory::IndustryFactory() {}
IndustryFactory::~IndustryFactory() {}
Entity* IndustryFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::CONCRETEPRODUCER:
			return createConcreteProducer(Size::SMALL, xPos, yPos);
			break;
		case EntityType::STONEPRODUCER:
			return createStoneProducer(Size::SMALL, xPos, yPos);
			break;
		case EntityType::WOODPRODUCER:
			return createWoodProducer(Size::SMALL, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}
Entity* IndustryFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::CONCRETEPRODUCER:
			return createConcreteProducer(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::STONEPRODUCER:
			return createStoneProducer(Size::MEDIUM, xPos, yPos);
			break;
		case EntityType::WOODPRODUCER:
			return createWoodProducer(Size::MEDIUM, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}
Entity* IndustryFactory::createLargeEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::CONCRETEPRODUCER:
			return createConcreteProducer(Size::LARGE, xPos, yPos);
			break;
		case EntityType::STONEPRODUCER:
			return createStoneProducer(Size::LARGE, xPos, yPos);
			break;
		case EntityType::WOODPRODUCER:
			return createWoodProducer(Size::LARGE, xPos, yPos);
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