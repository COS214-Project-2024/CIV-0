#ifndef MONUMENT_H
#define MONUMENT_H

#include "Amenity.h"

/**
 * @class Monument
 * @brief Represents a monument entity within the game.
 *
 * The Monument class is a specific type of Amenity with its own unique characteristics
 * and behaviors. This class provides implementations for updating the monument's state 
 * and cloning itself.
 */
class Monument : public Amenity
{
public:
    /**
     * @brief Default constructor for the Monument class.
     */
    Monument();

    /**
     * @brief Constructs a Monument with specified attributes.
     * 
     * @param ec Configuration containing resource consumption and properties.
     * @param size Size of the monument.
     * @param xPos X-coordinate position of the monument.
     * @param yPos Y-coordinate position of the monument.
     */
    Monument(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Monument class.
     * 
     * Creates a new Monument by copying the attributes of an existing Monument.
     * 
     * @param monument Pointer to the Monument object to be copied.
     */
    Monument(Monument* monument);

    /**
     * @brief Destructor for the Monument class.
     */
    virtual ~Monument();

    /**
     * @brief Updates the monument's state.
     */
    void update();

    /**
     * @brief Creates a clone of the monument.
     * 
     * @return A pointer to the cloned Monument.
     */
    Entity* clone();
};

#endif // MONUMENT_H
