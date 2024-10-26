#ifndef TRANSPORTFACTORY_H
#define TRANSPORTFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/transport/BusStop.h"
#include "entities/transport/TrainStation.h"
#include "entities/transport/Airport.h"

/**
 * @class TransportFactory
 * @brief A factory class for creating transport-related entities such as bus stops, train stations, and airports.
 * 
 * This class inherits from EntityFactory and provides methods for creating small, medium,
 * and large transport entities of different types.
 */
class TransportFactory : public EntityFactory {
public:
    /**
     * @brief Constructor for the TransportFactory class.
     */
    TransportFactory();

    /**
     * @brief Destructor for the TransportFactory class.
     */
    ~TransportFactory();

    /**
     * @brief Creates a small transport entity of the specified type at the given position.
     * 
     * @param type The type of transport entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);

    /**
     * @brief Creates a medium transport entity of the specified type at the given position.
     * 
     * @param type The type of transport entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);

    /**
     * @brief Creates a large transport entity of the specified type at the given position.
     * 
     * @param type The type of transport entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);

private:
    /**
     * @brief Creates a bus stop of the specified size at the given position.
     * 
     * @param size The size of the bus stop to create.
     * @param xPos The x-coordinate of the bus stop's position.
     * @param yPos The y-coordinate of the bus stop's position.
     * @return A pointer to the created Entity.
     */
    Entity* createBusStop(Size size, int xPos, int yPos);

    /**
     * @brief Creates a train station of the specified size at the given position.
     * 
     * @param size The size of the train station to create.
     * @param xPos The x-coordinate of the train station's position.
     * @param yPos The y-coordinate of the train station's position.
     * @return A pointer to the created Entity.
     */
    Entity* createTrainStation(Size size, int xPos, int yPos);

    /**
     * @brief Creates an airport of the specified size at the given position.
     * 
     * @param size The size of the airport to create.
     * @param xPos The x-coordinate of the airport's position.
     * @param yPos The y-coordinate of the airport's position.
     * @return A pointer to the created Entity.
     */
    Entity* createAirport(Size size, int xPos, int yPos);
};

#endif // TRANSPORTFACTORY_H
