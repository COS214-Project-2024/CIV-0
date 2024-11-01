#ifndef WATERSUPPLYUPGRADE_H
#define WATERSUPPLYUPGRADE_H

#include "entities/utility/watersupply/WaterSupply.h"

/**
 * @class WaterSupplyUpgrade
 * @brief Represents an upgrade to a WaterSupply entity in the city builder simulation.
 *
 * The WaterSupplyUpgrade class extends the functionality of a WaterSupply, enhancing its capabilities
 * and acting as a wrapper around the existing WaterSupply object.
 */
class WaterSupplyUpgrade : public WaterSupply
{
public:
    /**
     * @brief Constructs a WaterSupplyUpgrade object based on an existing WaterSupply.
     * 
     * Initializes the upgrade with a reference to an existing WaterSupply, enhancing its features.
     * 
     * @param water Pointer to the WaterSupply being upgraded.
     */
    WaterSupplyUpgrade(WaterSupply* water);

    /**
     * @brief Copy constructor for the WaterSupplyUpgrade class.
     * 
     * Creates a new WaterSupplyUpgrade object by copying the attributes of an existing WaterSupplyUpgrade.
     * 
     * @param wSU Pointer to the existing WaterSupplyUpgrade object to be copied.
     */
    WaterSupplyUpgrade(WaterSupplyUpgrade* wSU);

    /**
     * @brief Destructor for the WaterSupplyUpgrade object.
     */
    virtual ~WaterSupplyUpgrade();

    /**
     * @brief Pure virtual function to update the upgraded water supply system.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function to clone the upgraded water supply system.
     * 
     * @return A pointer to a new cloned WaterSupplyUpgrade object.
     */
    virtual Entity* clone() = 0;

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    virtual Entity* upgrade() = 0;

    /**
     * @brief Retrieves the output of the upgraded water supply system.
     * 
     * @return The output value as an integer.
     */
    virtual int getOutput() = 0;

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    virtual Cost getCost() = 0;

protected:
    WaterSupply* waterSupply; ///< Pointer to the original WaterSupply that is being upgraded.
};

#endif // WATERSUPPLYUPGRADE_H
