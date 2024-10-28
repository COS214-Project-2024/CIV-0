#ifndef AIRPORT_H
#define AIRPORT_H

#include "Transport.h"

/**
 * @class Airport
 * @brief Represents an airport entity within the game.
 *
 * The Airport class manages the properties and behavior of airport entities, 
 * including their position, size, and functionality related to transportation.
 */
class Airport : public Transport
{
public:
    /**
     * @brief Default constructor for the Airport class.
     */
    Airport();

    /**
     * @brief Constructs an Airport entity with specified attributes.
     * 
     * @param ec Configuration settings for the entity.
     * @param size Size of the airport entity.
     * @param xPos X-coordinate position of the airport.
     * @param yPos Y-coordinate position of the airport.
     */
    Airport(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Airport class.
     * 
     * Creates a new Airport entity by copying the attributes of an existing Airport.
     * 
     * @param airport Pointer to the Airport object to be copied.
     */
    Airport(Airport* airport);

    /**
     * @brief Destructor for the Airport class.
     */
    virtual ~Airport();

    /**
     * @brief Updates the state of the airport entity.
     */
    void update();

    /**
     * @brief Creates a clone of the airport entity.
     * 
     * @return A pointer to the cloned Airport entity.
     */
    Entity* clone();
};

#endif // AIRPORT_H