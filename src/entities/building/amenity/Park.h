#ifndef PARK_H
#define PARK_H

#include "Amenity.h"

/**
 * @brief Class representing a park in the city.
 * 
 * The Park class provides a recreational area for the population.
 * It inherits from the Amenity class.
 */
class Park : public Amenity
{
public:
    /**
     * @brief Default constructor for the Park class.
     * 
     * Initializes an empty park object.
     */
    Park();

    /**
     * @brief Parameterized constructor for the Park class.
     * 
     * @param ec Entity configuration for initializing the park.
     * @param size The size of the park.
     * @param xPos The x-coordinate of the park's location.
     * @param yPos The y-coordinate of the park's location.
     */
    Park(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Park class.
     * 
     * @param park A pointer to an existing Park object to copy from.
     */
    Park(Park* park);

    /**
     * @brief Destructor for the Park class.
     * 
     * Cleans up resources used by the Park object.
     */
    ~Park();

    /**
     * @brief Updates the state of the park entity.
     * 
     * Handles changes in the park's state.
     */
    void update();

    /**
     * @brief Clones the park entity.
     * 
     * @return A pointer to a deep copy of the Park object.
     */
    Entity* clone();
};

#endif // PARK_H