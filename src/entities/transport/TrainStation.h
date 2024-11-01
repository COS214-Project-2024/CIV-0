#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "Transport.h"

/**
 * @class TrainStation
 * @brief Represents a train station entity within the game.
 *
 * The TrainStation class manages the properties and behavior of train station entities,
 * including their position, size, and functionality related to transportation.
 */
class TrainStation : public Transport
{
public:
    /**
     * @brief Default constructor for the TrainStation class.
     */
    TrainStation();

    /**
     * @brief Constructs a TrainStation entity with specified attributes.
     * 
     * @param ec Configuration settings for the entity.
     * @param size Size of the train station entity.
     * @param xPos X-coordinate position of the train station.
     * @param yPos Y-coordinate position of the train station.
     */
    TrainStation(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the TrainStation class.
     * 
     * Creates a new TrainStation entity by copying the attributes of an existing TrainStation.
     * 
     * @param trainStation Pointer to the TrainStation object to be copied.
     */
    TrainStation(TrainStation* trainStation);

    /**
     * @brief Destructor for the TrainStation class.
     */
    virtual ~TrainStation();

    /**
     * @brief Updates the state of the train station entity.
     */
    void update();

    /**
     * @brief Creates a clone of the train station entity.
     * 
     * @return A pointer to the cloned TrainStation entity.
     */
    Entity* clone();
};

#endif // TRAINSTATION_H