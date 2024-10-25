#ifndef ECONOMICBUILDING_H
#define ECONOMICBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Subject.h"
#include "entities/building/residential/ResidentialBuilding.h"

/**
 * @class EconomicBuilding
 * @brief Abstract class representing economic buildings in the city builder/manager game.
 * 
 * EconomicBuilding is a type of Building that generates revenue or supports the city's economy.
 * It inherits from both the Building and Subject classes.
 */
class EconomicBuilding : public Building, public Subject
{
public:
    /**
     * @brief Default constructor for the EconomicBuilding class.
     * 
     * Initializes a new instance of the EconomicBuilding class with default values.
     */
    EconomicBuilding();

    /**
     * @brief Parameterized constructor for the EconomicBuilding class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the economic building entity.
     * @param xPos The x-coordinate position of the economic building on the map.
     * @param yPos The y-coordinate position of the economic building on the map.
     * 
     * Initializes a new instance of the EconomicBuilding class with specific values.
     */
    EconomicBuilding(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the EconomicBuilding class.
     * 
     * @param economic A pointer to an existing EconomicBuilding object to copy from.
     * 
     * Creates a new EconomicBuilding instance as a copy of the provided object.
     */
    EconomicBuilding(EconomicBuilding* economic);

    /**
     * @brief Destructor for the EconomicBuilding class.
     * 
     * Ensures proper cleanup of resources when an EconomicBuilding object is destroyed.
     */
    virtual ~EconomicBuilding();

    /**
     * @brief Updates the state of the economic building entity.
     * 
     * A pure virtual function that must be implemented by derived classes to handle changes in the economic building's state.
     */
    virtual void update() = 0;

    /**
     * @brief Clones the economic building entity.
     * 
     * Returns a deep copy of the current EconomicBuilding object.
     * 
     * @return A pointer to the newly cloned EconomicBuilding entity.
     */
    virtual Entity* clone() = 0;
};

#endif // ECONOMICBUILDING_H