#ifndef THEATER_H
#define THEATER_H

#include "Amenity.h"

/**
 * @brief Class representing a theater in the city.
 * 
 * The Theater class provides an entertainment venue for the population.
 * It inherits from the Amenity class.
 */
class Theater : public Amenity
{
public:
    /**
     * @brief Default constructor for the Theater class.
     * 
     * Initializes an empty theater object.
     */
    Theater();

    /**
     * @brief Parameterized constructor for the Theater class.
     * 
     * @param ec Entity configuration for initializing the theater.
     * @param size The size of the theater.
     * @param xPos The x-coordinate of the theater's location.
     * @param yPos The y-coordinate of the theater's location.
     */
    Theater(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Theater class.
     * 
     * @param theater A pointer to an existing Theater object to copy from.
     */
    Theater(Theater* theater);

    /**
     * @brief Destructor for the Theater class.
     * 
     * Cleans up resources used by the Theater object.
     */
    ~Theater();

    /**
     * @brief Updates the state of the theater entity.
     * 
     * Handles changes in the theater's state.
     */
    void update();

    /**
     * @brief Clones the theater entity.
     * 
     * @return A pointer to a deep copy of the Theater object.
     */
    Entity* clone();
};

#endif // THEATER_H