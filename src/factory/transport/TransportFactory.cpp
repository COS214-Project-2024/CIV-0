
#include "TransportFactory.h"
TransportFactory::TransportFactory() {

}
TransportFactory::~TransportFactory() {
    
}

Entity* TransportFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
    switch (type) {
        case EntityType::BUSSTOP:
            return createBusStop(Size::SMALL, xPos, yPos);
            break;
        case EntityType::TRAINSTATION:
            return createTrainStation(Size::SMALL, xPos, yPos);
            break;
        case EntityType::AIRPORT:
            return createAirport(Size::SMALL, xPos, yPos);
            break;
        default:
            return nullptr;
    }
}

Entity* TransportFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
    switch (type) {
        case EntityType::BUSSTOP:
            return createBusStop(Size::MEDIUM, xPos, yPos);
            break;
        case EntityType::TRAINSTATION:
            return createTrainStation(Size::MEDIUM, xPos, yPos);
            break;
        case EntityType::AIRPORT:
            return createAirport(Size::MEDIUM, xPos, yPos);
            break;
        default:
            return nullptr;
    }
}

Entity* TransportFactory::createLargeEntity(EntityType type, int xPos, int yPos) {
    switch (type) {
        case EntityType::BUSSTOP:
            return createBusStop(Size::LARGE, xPos, yPos);
            break;
        case EntityType::TRAINSTATION:
            return createTrainStation(Size::LARGE, xPos, yPos);
            break;
        case EntityType::AIRPORT:
            return createAirport(Size::LARGE, xPos, yPos);
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
