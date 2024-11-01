#ifndef BUILDING_H
#define BUILDING_H

#include "entities/base/Entity.h"

/**
 * @class Building
 * @brief Abstract class representing a general building entity in the city builder/manager game.
 * 
 * This class serves as the base class for all types of buildings. It inherits from the Entity class 
 * and provides an interface for common building functionalities.
 */
class Building : public Entity
{
public:
    /**
     * @brief Parameterized constructor for the Building class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the building entity.
     * @param xPos The x-coordinate position of the building on the map.
     * @param yPos The y-coordinate position of the building on the map.
     * 
     * Initializes a new instance of the Building class with specific values.
     */
    Building(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Building class.
     * 
     * @param building A pointer to an existing Building object to copy from.
     * 
     * Creates a new Building instance as a copy of the provided object.
     */
    Building(Building* building);

    /**
     * @brief Destructor for the Building class.
     * 
     * Ensures proper cleanup of resources when a Building object is destroyed.
     */
    virtual ~Building();

    /**
     * @brief Updates the state of the building entity.
     * 
     * A pure virtual function that must be implemented by derived classes to handle changes in the building's state.
     */
    virtual void update() = 0;

    /**
     * @brief Clones the building entity.
     * 
     * Returns a deep copy of the current Building object.
     * 
     * @return A pointer to the newly cloned Building entity.
     */
    virtual Entity* clone() = 0;
};

#endif // BUILDING_H
