#ifndef AIRPORT_H
#define AIRPORT_H

#include "Transport.h"

/**
 * @class Airport
 * @brief Concrete class representing an airport in the city builder/manager game.
 * 
 * Airport is a specific type of transport entity that handles air transport operations.
 * It inherits from the Transport class and implements the necessary functions.
 */
class Airport : public Transport
{
public:
    /**
     * @brief Default constructor for the Airport class.
     * 
     * Initializes a new instance of the Airport class with default values.
     */
    Airport();

    /**
     * @brief Parameterized constructor for the Airport class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the airport entity.
     * @param xPos The x-coordinate position of the airport on the map.
     * @param yPos The y-coordinate position of the airport on the map.
     * 
     * Initializes a new instance of the Airport class with specific values.
     */
    Airport(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Airport class.
     * 
     * @param airport A pointer to an existing Airport object to copy from.
     * 
     * Creates a new Airport instance as a copy of the provided object.
     */
    Airport(Airport* airport);

    /**
     * @brief Destructor for the Airport class.
     * 
     * Ensures proper cleanup of resources when an Airport object is destroyed.
     */
    virtual ~Airport();

    /**
     * @brief Updates the state of the airport entity.
     * 
     * This function handles changes in the airport's state.
     */
    void update();

    /**
     * @brief Clones the airport entity.
     * 
     * Returns a deep copy of the current Airport object, used for duplicating the airport.
     * 
     * @return A pointer to the newly cloned Airport entity.
     */
    Entity* clone();
};

#endif // AIRPORT_H