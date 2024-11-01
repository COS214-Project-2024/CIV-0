#ifndef TRANSPORTFACTORY_H
#define TRANSPORTFACTORY_H

#include "entities/transport/Airport.h"
#include "entities/transport/BusStop.h"
#include "entities/transport/TrainStation.h"
#include "factory/base/EntityFactory.h"

/**
 * @class TransportFactory
 * @brief Factory class for creating transport-related entities, including bus stops, train stations, and airports.
 * 
 * Inherits from EntityFactory and provides methods for creating transport entities of various sizes 
 * (small, medium, and large) positioned at specified coordinates.
 */
class TransportFactory : public EntityFactory {
   public:
    /**
     * @brief Default constructor for TransportFactory.
     */
    TransportFactory();

    /**
     * @brief Destructor for TransportFactory.
     */
    ~TransportFactory();

    /**
     * @brief Creates a transport entity of the specified type and size at the given position.
     * 
     * @param type The type of transport entity to create (e.g., BusStop, TrainStation, Airport).
     * @param size The size of the entity (small, medium, or large).
     * @param xPos The x-coordinate for the entity’s position.
     * @param yPos The y-coordinate for the entity’s position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos);

   private:
    /**
     * @brief Creates a bus stop of the specified size at a given position.
     * 
     * @param size Size of the bus stop (small, medium, or large).
     * @param xPos X-coordinate for the bus stop’s position.
     * @param yPos Y-coordinate for the bus stop’s position.
     * @return A pointer to the created BusStop entity.
     */
    Entity* createBusStop(Size size, int xPos, int yPos);

    /**
     * @brief Creates a train station of the specified size at a given position.
     * 
     * @param size Size of the train station (small, medium, or large).
     * @param xPos X-coordinate for the train station’s position.
     * @param yPos Y-coordinate for the train station’s position.
     * @return A pointer to the created TrainStation entity.
     */
    Entity* createTrainStation(Size size, int xPos, int yPos);

    /**
     * @brief Creates an airport of the specified size at a given position.
     * 
     * @param size Size of the airport (small, medium, or large).
     * @param xPos X-coordinate for the airport’s position.
     * @param yPos Y-coordinate for the airport’s position.
     * @return A pointer to the created Airport entity.
     */
    Entity* createAirport(Size size, int xPos, int yPos);
};

#endif // TRANSPORTFACTORY_H
