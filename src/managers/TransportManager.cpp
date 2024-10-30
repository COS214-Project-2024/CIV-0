#include "TransportManager.h"

#include "city/City.h"
#include "utils/ConfigManager.h"
TransportManager::TransportManager() {}
TransportManager::~TransportManager() {}

bool TransportManager::canAffordRoad() {
	EntityConfig roadConfig = ConfigManager::getEntityConfig(EntityType::ROAD, Size::SMALL);
	City* city = City::instance();
	if (roadConfig.cost.moneyCost <= city->getMoney() && roadConfig.cost.woodCost <= city->getWood() && roadConfig.cost.stoneCost <= city->getStone() && roadConfig.cost.concreteCost <= city->getConcrete()) {
		return true;
	}
	return false;
}

bool TransportManager::buildRoad(int x, int y) {
	if (canAffordRoad()) {
		EntityConfig roadConfig = ConfigManager::getEntityConfig(EntityType::ROAD, Size::SMALL);
		City* city = City::instance();
		city->addEntity(new Road(roadConfig, Size::SMALL, x, y));
		return true;
	}
	return false;
}
bool TransportManager::canAffordPublicTransit(EntityType type, Size size) {
	EntityConfig entityConfig = ConfigManager::getEntityConfig(type, size);
	City* city = City::instance();
	if (entityConfig.cost.moneyCost <= city->getMoney() && entityConfig.cost.woodCost <= city->getWood() && entityConfig.cost.stoneCost <= city->getStone() && entityConfig.cost.concreteCost <= city->getConcrete()) {
		return true;
	}
	return false;
}

bool TransportManager::buildPublicTransit(EntityType type, Size size, int x, int y) {
	if (!canAffordPublicTransit(type, size)) {
		return false;
	}
	TransportFactory* fact = new TransportFactory();
	City* city = City::instance();
	switch (size) {
		case Size::SMALL:
			city->addEntity(fact->createSmallEntity(type, x, y));
			break;
		case Size::MEDIUM:
			city->addEntity(fact->createMediumEntity(type, x, y));
			break;
		case Size::LARGE:
			city->addEntity(fact->createLargeEntity(type, x, y));
			break;
	}
	delete fact;
	return true;
}
