#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "Transport.h"

/**
 * @class TrainStation
 * @brief Concrete class representing a train station in the city builder/manager game.
 * 
 * TrainStation is a specific type of transport entity that handles rail transportation.
 * It inherits from the Transport class and implements the necessary functions.
 */
class TrainStation : public Transport
{
public:
    /**
     * @brief Default constructor for the TrainStation class.
     * 
     * Initializes a new instance of the TrainStation class with default values.
     */
    TrainStation();

    /**
     * @brief Parameterized constructor for the TrainStation class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the train station entity.
     * @param xPos The x-coordinate position of the train station on the map.
     * @param yPos The y-coordinate position of the train station on the map.
     * 
     * Initializes a new instance of the TrainStation class with specific values.
     */
    TrainStation(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the TrainStation class.
     * 
     * @param TrainStation A pointer to an existing TrainStation object to copy from.
     * 
     * Creates a new TrainStation instance as a copy of the provided object.
     */
    TrainStation(TrainStation* TrainStation);

    /**
     * @brief Destructor for the TrainStation class.
     * 
     * Ensures proper cleanup of resources when a TrainStation object is destroyed.
     */
    ~TrainStation();

    /**
     * @brief Updates the state of the train station entity.
     * 
     * This function handles changes in the train station's state.
     */
    void update();

    /**
     * @brief Clones the train station entity.
     * 
     * Returns a deep copy of the current TrainStation object, used for duplicating the train station.
     * 
     * @return A pointer to the newly cloned TrainStation entity.
     */
    Entity* clone();
};

#endif // TRAINSTATION_H