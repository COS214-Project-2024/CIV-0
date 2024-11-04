#ifndef AMENITY_H
#define AMENITY_H

#include "entities/building/base/Building.h"
#include "entities/building/residential/ResidentialBuilding.h"

/**
 * @class Amenity
 * @brief Represents an abstract base class for amenities within the game, such as parks, shops, or other facilities.
 *
 * This class inherits from Building and provides a foundation for various types
 * of amenities that can be added to the game. It includes basic constructors, 
 * a destructor, and pure virtual methods for update and cloning operations.
 */
class Amenity : public Building
{
public:
    /**
     * @brief Constructs an Amenity with specified attributes.
     * 
     * @param ec Configuration containing resource consumption and other properties.
     * @param size Size of the amenity.
     * @param xPos X-coordinate position of the amenity.
     * @param yPos Y-coordinate position of the amenity.
     */
    Amenity(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Amenity class.
     * 
     * Creates a new Amenity by copying the attributes of an existing Amenity.
     * 
     * @param amenity Pointer to the Amenity object to be copied.
     */
    Amenity(Amenity* amenity);

    /**
     * @brief Virtual destructor for the Amenity class.
     */
    virtual ~Amenity();

    /**
     * @brief Updates the amenity's state. Needs to be implemented in derived classes.
     */
    virtual void update() = 0;

    /**
     * @brief Clones the amenity. Needs to be implemented in derived classes.
     * 
     * @return A pointer to the cloned Amenity.
     */
    virtual Entity* clone() = 0;
};

#endif // AMENITY_H