#ifndef BUSSTOP_H
#define BUSSTOP_H

#include "Transport.h"

/**
 * @class BusStop
 * @brief Concrete class representing a bus stop in the city builder/manager game.
 * 
 * BusStop is a specific type of transport entity that handles ground-based bus transportation.
 * It inherits from the Transport class and implements the necessary functions.
 */
class BusStop : public Transport
{
public:
    /**
     * @brief Default constructor for the BusStop class.
     * 
     * Initializes a new instance of the BusStop class with default values.
     */
    BusStop();

    /**
     * @brief Parameterized constructor for the BusStop class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the bus stop entity.
     * @param xPos The x-coordinate position of the bus stop on the map.
     * @param yPos The y-coordinate position of the bus stop on the map.
     * 
     * Initializes a new instance of the BusStop class with specific values.
     */
    BusStop(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the BusStop class.
     * 
     * @param busStop A pointer to an existing BusStop object to copy from.
     * 
     * Creates a new BusStop instance as a copy of the provided object.
     */
    BusStop(BusStop* busStop);

    /**
     * @brief Destructor for the BusStop class.
     * 
     * Ensures proper cleanup of resources when a BusStop object is destroyed.
     */
    ~BusStop();

    /**
     * @brief Updates the state of the bus stop entity.
     * 
     * This function handles changes in the bus stop's state.
     */
    void update();

    /**
     * @brief Clones the bus stop entity.
     * 
     * Returns a deep copy of the current BusStop object, used for duplicating the bus stop.
     * 
     * @return A pointer to the newly cloned BusStop entity.
     */
    Entity* clone();
};

#endif // BUSSTOP_H