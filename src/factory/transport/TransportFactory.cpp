
#include "TransportFactory.h"
TransportFactory::TransportFactory() {
}
TransportFactory::~TransportFactory() {
}

Entity* TransportFactory::createEntity(EntityType type, Size size, int xPos, int yPos) {
	switch (type) {
		case EntityType::BUSSTOP:
			return createBusStop(size, xPos, yPos);
			break;
		case EntityType::TRAINSTATION:
			return createTrainStation(size, xPos, yPos);
			break;
		case EntityType::AIRPORT:
			return createAirport(size, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* TransportFactory::createBusStop(Size size, int xPos, int yPos) {
	return new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, size), size, xPos, yPos);
}

Entity* TransportFactory::createTrainStation(Size size, int xPos, int yPos) {
	return new TrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, size), size, xPos, yPos);
}

Entity* TransportFactory::createAirport(Size size, int xPos, int yPos) {
	return new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, size), size, xPos, yPos);
}
