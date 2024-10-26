#ifndef BUSSTOP_H
#define BUSSTOP_H

#include "Transport.h"

/**
 * @class BusStop
 * @brief Represents a bus stop entity within the game.
 *
 * The BusStop class manages the properties and behavior of bus stop entities,
 * including their position, size, and functionality related to transportation.
 */
class BusStop : public Transport
{
public:
    /**
     * @brief Default constructor for the BusStop class.
     */
    BusStop();

    /**
     * @brief Constructs a BusStop entity with specified attributes.
     * 
     * @param ec Configuration settings for the entity.
     * @param size Size of the bus stop entity.
     * @param xPos X-coordinate position of the bus stop.
     * @param yPos Y-coordinate position of the bus stop.
     */
    BusStop(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the BusStop class.
     * 
     * Creates a new BusStop entity by copying the attributes of an existing BusStop.
     * 
     * @param busStop Pointer to the BusStop object to be copied.
     */
    BusStop(BusStop* busStop);

    /**
     * @brief Destructor for the BusStop class.
     */
    virtual ~BusStop();

    /**
     * @brief Updates the state of the bus stop entity.
     */
    void update();

    /**
     * @brief Creates a clone of the bus stop entity.
     * 
     * @return A pointer to the cloned BusStop entity.
     */
    Entity* clone();
};

#endif // BUSSTOP_H
