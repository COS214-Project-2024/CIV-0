#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "entities/utility/base/Utility.h"

class PowerPlantLevelOneUpgrade;

/**
 * @class PowerPlant
 * @brief Represents a power plant in the city builder simulation.
 *
 * The PowerPlant class is a specialized type of Utility that produces electricity.
 */
class PowerPlant : public Utility
{
public:
    /**
     * @brief Constructs a PowerPlant object with specified attributes.
     *
     * Initializes a PowerPlant with detailed parameters.
     *
     * @param ec        EntityConfig.
     * @param size      Size.
     * @param xPos      xPosition
     * @param yPos      yPosition
     */
    PowerPlant(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the PowerPlant class.
     *
     * Creates a new PowerPlant object by copying the attributes of an existing PowerPlant.
     *
     * @param power Pointer to the existing PowerPlant object to be copied.
     */
    PowerPlant(PowerPlant *power);

    /**
     * @brief Default constructor for the PowerPlant class.
     *
     * Creates a new PowerPlant object without initializing any of it's values (naughty).
     */
    PowerPlant();

    /**
     * @brief Destructor for the PowerPlant object.
     */
    virtual ~PowerPlant();

    /**
     * @brief Updates the state of the power plant.
     *
     * Defines the specific behavior of the PowerPlant when it is updated in the simulation.
     */
    void update();

    /**
     * @brief Clones the current PowerPlant object.
     *
     * Creates and returns a copy of the current PowerPlant instance.
     *
     * @return A pointer to the newly cloned PowerPlant object.
     */
    Entity *clone();

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade();
};

#endif // POWERPLANT_H
