#ifndef MONUMENT_H
#define MONUMENT_H

#include "Amenity.h"

/**
 * @brief Class representing a monument in the city.
 * 
 * The Monument class provides a decorative or commemorative structure to enhance the city's appeal.
 * It inherits from the Amenity class.
 */
class Monument : public Amenity
{
public:
    /**
     * @brief Default constructor for the Monument class.
     * 
     * Initializes an empty monument object.
     */
    Monument();

    /**
     * @brief Parameterized constructor for the Monument class.
     * 
     * @param ec Entity configuration for initializing the monument.
     * @param size The size of the monument.
     * @param xPos The x-coordinate of the monument's location.
     * @param yPos The y-coordinate of the monument's location.
     */
    Monument(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Monument class.
     * 
     * @param monument A pointer to an existing Monument object to copy from.
     */
    Monument(Monument* monument);

    /**
     * @brief Destructor for the Monument class.
     * 
     * Cleans up resources used by the Monument object.
     */
    ~Monument();

    /**
     * @brief Updates the state of the monument entity.
     * 
     * Handles changes in the monument's state.
     */
    void update();

    /**
     * @brief Clones the monument entity.
     * 
     * @return A pointer to a deep copy of the Monument object.
     */
    Entity* clone();
};

#endif // MONUMENT_H