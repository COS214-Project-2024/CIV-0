#ifndef PARK_H
#define PARK_H

#include "Amenity.h"

/**
 * @class Park
 * @brief Represents a park entity within the game.
 *
 * The Park class is a specific type of Amenity that provides unique attributes 
 * and behaviors specific to parks, such as improving nearby area aesthetics.
 * This class implements the methods to update its state and clone itself.
 */
class Park : public Amenity
{
public:
    /**
     * @brief Default constructor for the Park class.
     */
    Park();

    /**
     * @brief Constructs a Park with specified attributes.
     * 
     * @param ec Configuration containing resource consumption and properties.
     * @param size Size of the park.
     * @param xPos X-coordinate position of the park.
     * @param yPos Y-coordinate position of the park.
     */
    Park(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Park class.
     * 
     * Creates a new Park by copying the attributes of an existing Park.
     * 
     * @param park Pointer to the Park object to be copied.
     */
    Park(Park* park);

    /**
     * @brief Destructor for the Park class.
     */
    virtual ~Park();

    /**
     * @brief Updates the park's state.
     */
    void update();

    /**
     * @brief Creates a clone of the park.
     * 
     * @return A pointer to the cloned Park.
     */
    Entity* clone();
};

#endif // PARK_H