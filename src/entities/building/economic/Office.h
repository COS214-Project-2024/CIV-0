#ifndef OFFICE_H
#define OFFICE_H

#include "EconomicBuilding.h"

/**
 * @class Office
 * @brief Concrete class representing an office building in the city builder/manager game.
 * 
 * Office is a type of EconomicBuilding that houses businesses and supports administrative activities.
 */
class Office : public EconomicBuilding
{
public:
    /**
     * @brief Default constructor for the Office class.
     * 
     * Initializes a new instance of the Office class with default values.
     */
    Office();

    /**
     * @brief Parameterized constructor for the Office class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the office entity.
     * @param xPos The x-coordinate position of the office on the map.
     * @param yPos The y-coordinate position of the office on the map.
     * 
     * Initializes a new instance of the Office class with specific values.
     */
    Office(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Office class.
     * 
     * @param office A pointer to an existing Office object to copy from.
     * 
     * Creates a new Office instance as a copy of the provided object.
     */
    Office(Office* office);

    /**
     * @brief Destructor for the Office class.
     * 
     * Ensures proper cleanup of resources when an Office object is destroyed.
     */
    ~Office();

    /**
     * @brief Updates the state of the office building entity.
     * 
     * This function handles changes in the office's state.
     */
    void update();

    /**
     * @brief Clones the office entity.
     * 
     * Returns a deep copy of the current Office object.
     * 
     * @return A pointer to the newly cloned Office entity.
     */
    Entity* clone();
};

#endif // OFFICE_H