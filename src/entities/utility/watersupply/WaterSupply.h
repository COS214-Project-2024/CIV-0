#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "entities/utility/base/Utility.h"

class WaterSupplyLevelOneUpgrade;

/**
 * @class WaterSupply
 * @brief Represents a water supply system in the city builder simulation.
 *
 * The WaterSupply class is a type of Utility responsible for providing water to the city.
 */
class WaterSupply : public Utility
{
public:
    /**
     * @brief Constructs a WaterSupply object with specified attributes.
     *
     * Initializes a WaterSupply facility with detailed parameters, including utility consumption, effects, and dimensions.
     *
     * @param ec        EntityConfig.
     * @param size      Size.
     * @param xPos      xPosition
     * @param yPos      yPosition
     */
    WaterSupply(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the WaterSupply class.
     *
     * Creates a new WaterSupply object by copying the attributes of an existing WaterSupply.
     *
     * @param water Pointer to the existing WaterSupply object to be copied.
     */
    WaterSupply(WaterSupply *water);

    /**
     * @brief Destructor for the WaterSupply object.
     */
    virtual ~WaterSupply();

    /**
     * @brief Updates the state of the water supply system.
     *
     * Defines the specific behavior of the WaterSupply system when it is updated in the simulation.
     */
    void update();

    /**
     * @brief Clones the current WaterSupply object.
     *
     * Creates and returns a copy of the current WaterSupply instance.
     *
     * @return A pointer to the newly cloned WaterSupply object.
     */
    Entity *clone();

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade();
};

#endif // WATERSUPPLY_H
