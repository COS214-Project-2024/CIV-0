#ifndef FACTORY_H
#define FACTORY_H

#include "EconomicBuilding.h"

/**
 * @class Factory
 * @brief Concrete class representing a factory in the city builder/manager game.
 * 
 * Factory is a type of EconomicBuilding that produces goods and supports industrial activities.
 */
class Factory : public EconomicBuilding
{
public:
    /**
     * @brief Default constructor for the Factory class.
     * 
     * Initializes a new instance of the Factory class with default values.
     */
    Factory();

    /**
     * @brief Parameterized constructor for the Factory class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the factory entity.
     * @param xPos The x-coordinate position of the factory on the map.
     * @param yPos The y-coordinate position of the factory on the map.
     * 
     * Initializes a new instance of the Factory class with specific values.
     */
    Factory(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Factory class.
     * 
     * @param factory A pointer to an existing Factory object to copy from.
     * 
     * Creates a new Factory instance as a copy of the provided object.
     */
    Factory(Factory* factory);

    /**
     * @brief Destructor for the Factory class.
     * 
     * Ensures proper cleanup of resources when a Factory object is destroyed.
     */
    ~Factory();

    /**
     * @brief Updates the state of the factory entity.
     * 
     * This function handles changes in the factory's state.
     */
    void update();

    /**
     * @brief Clones the factory entity.
     * 
     * Returns a deep copy of the current Factory object.
     * 
     * @return A pointer to the newly cloned Factory entity.
     */
    Entity* clone();
};

#endif // FACTORY_H
