#include "TransportFactory.h"

TransportFactory::TransportFactory() {

}
TransportFactory::~TransportFactory() {
    
}

Entity* TransportFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
	return nullptr;
}

Entity* TransportFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
	return nullptr;
}

Entity* TransportFactory::createLargeEntity(EntityType type, int xPos, int yPos) {
	return nullptr;
}

Entity* TransportFactory::createBusStop(Size size, int xPos, int yPos) {
	return nullptr;
}

Entity* TransportFactory::createTrainStation(Size size, int xPos, int yPos) {
	return nullptr;
}

Entity* TransportFactory::createAirport(Size size, int xPos, int yPos) {
	return nullptr;
}
