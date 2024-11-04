#ifndef WATERSUPPLYLEVELTHREEUPGRADE_H
#define WATERSUPPLYLEVELTHREEUPGRADE_H

#include "WaterSupplyUpgrade.h"

/**
 * @class WaterSupplyLevelThreeUpgrade
 * @brief Represents the third level upgrade to a WaterSupply entity.
 *
 * The WaterSupplyLevelThreeUpgrade class enhances the base functionality of a WaterSupply by increasing
 * its delivery capacity. This class is the third upgrade level in a series of potential water supply improvements.
 */
class WaterSupplyLevelThreeUpgrade : public WaterSupplyUpgrade
{
public:
    /**
     * @brief Constructs a WaterSupplyLevelThreeUpgrade object.
     *
     * Initializes the upgrade by enhancing the specified WaterSupply with a level three upgrade.
     *
     * @param water Pointer to the original WaterSupply to be upgraded.
     */
    WaterSupplyLevelThreeUpgrade(WaterSupply *water);

    /**
     * @brief Copy constructor for WaterSupplyLevelThreeUpgrade.
     *
     * Creates a new WaterSupplyLevelThreeUpgrade object by copying the attributes of an existing
     * WaterSupplyLevelThreeUpgrade object.
     * 
     * @param wSLTU Pointer to the existing WaterSupplyLevelThreeUpgrade to be copied.
     */
    WaterSupplyLevelThreeUpgrade(WaterSupplyLevelThreeUpgrade *wSLTU);

    /**
     * @brief Destructor for WaterSupplyLevelThreeUpgrade.
     *
     * Cleans up any resources associated with the upgrade.
     */
    ~WaterSupplyLevelThreeUpgrade();

    /**
     * @brief Updates the state of the upgraded water supply system.
     *
     * Implements specific behavior for the water supply system after applying the level three upgrade.
     */
    void update() override;

    /**
     * @brief Clones the current WaterSupplyLevelThreeUpgrade object.
     *
     * Creates a new instance of WaterSupplyLevelThreeUpgrade with the same attributes as the current object.
     *
     * @return A pointer to the newly cloned WaterSupplyLevelThreeUpgrade object.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade() override;

    /**
     * @brief Retrieves the upgraded water supply system's output.
     *
     * Returns the delivery capacity of the level three upgraded water supply system.
     *
     * @return The updated delivery capacity as an integer.
     */
    int getOutput() override;

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    Cost getCost() override;

    /**
     * @brief Gets the level of the water supply upgrade.
     *
     * @return The level of the water supply upgrade.
     */
    int getLevel() override;

private:
    const int UPGRADE = 6; ///< Multiplier applied to the original delivery capacity for the level three upgrade.
};

#endif // WATERSUPPLYLEVELTHREEUPGRADE_H
