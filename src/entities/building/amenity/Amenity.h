#ifndef AMENITY_H
#define AMENITY_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"
#include "entities/building/residential/ResidentialBuilding.h"

/**
 * @brief Abstract class representing an amenity building in the city.
 * 
 * Amenities provide non-essential but beneficial services, like parks, monuments, or theaters.
 * It inherits from the Building and Subject classes.
 */
class Amenity : public Building, public Subject
{
public:
    /**
     * @brief Default constructor for the Amenity class.
     * 
     * Initializes an empty amenity object.
     */
    Amenity();

    /**
     * @brief Parameterized constructor for the Amenity class.
     * 
     * @param ec Entity configuration for initializing the amenity.
     * @param size The size of the amenity.
     * @param xPos The x-coordinate of the amenity's location.
     * @param yPos The y-coordinate of the amenity's location.
     */
    Amenity(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Amenity class.
     * 
     * @param amenity A pointer to an existing Amenity object to copy from.
     */
    Amenity(Amenity* amenity);

    /**
     * @brief Destructor for the Amenity class.
     * 
     * Cleans up resources used by the Amenity object.
     */
    virtual ~Amenity();

    /**
     * @brief Pure virtual function for updating the state of the amenity.
     * 
     * Must be implemented by derived classes to handle amenity-specific updates.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function for cloning the amenity.
     * 
     * @return A pointer to a deep copy of the amenity object.
     */
    virtual Entity* clone() = 0;
};

#endif // AMENITY_H