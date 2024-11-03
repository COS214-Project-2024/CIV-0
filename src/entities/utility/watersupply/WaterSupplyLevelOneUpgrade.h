#ifndef WATERSUPPLYLEVELONEUPGRADE_H
#define WATERSUPPLYLEVELONEUPGRADE_H

#include "WaterSupplyUpgrade.h"

class WaterSupplyLevelTwoUpgrade;

/**
 * @class WaterSupplyLevelOneUpgrade
 * @brief Represents the first level upgrade to a WaterSupply entity.
 *
 * The WaterSupplyLevelOneUpgrade class enhances the base functionality of a WaterSupply by increasing
 * its output. This class is the first upgrade level in a series of potential water supply improvements.
 */
class WaterSupplyLevelOneUpgrade : public WaterSupplyUpgrade
{
public:
    /**
     * @brief Constructs a WaterSupplyLevelOneUpgrade object.
     *
     * Initializes the upgrade by enhancing the specified WaterSupply with a level one upgrade.
     *
     * @param water Pointer to the original WaterSupply to be upgraded.
     */
    WaterSupplyLevelOneUpgrade(WaterSupply *water);

    /**
     * @brief Copy constructor for WaterSupplyLevelOneUpgrade.
     *
     * Creates a new WaterSupplyLevelOneUpgrade object by copying the attributes of an existing
     * WaterSupplyLevelOneUpgrade object.
     * 
     * @param wSLOU Pointer to the existing WaterSupplyLevelOneUpgrade to be copied.
     */
    WaterSupplyLevelOneUpgrade(WaterSupplyLevelOneUpgrade *wSLOU);

    /**
     * @brief Destructor for WaterSupplyLevelOneUpgrade.
     *
     * Cleans up any resources associated with the upgrade.
     */
    ~WaterSupplyLevelOneUpgrade();

    /**
     * @brief Updates the state of the upgraded water supply system.
     *
     * Implements specific behavior for the water supply system after applying the level one upgrade.
     */
    void update() override;

    /**
     * @brief Clones the current WaterSupplyLevelOneUpgrade object.
     *
     * Creates a new instance of WaterSupplyLevelOneUpgrade with the same attributes as the current object.
     *
     * @return A pointer to the newly cloned WaterSupplyLevelOneUpgrade object.
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
     * Returns the output of the level one upgraded water supply system.
     *
     * @return The updated output as an integer.
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
    const int UPGRADE = 2; ///< Multiplier applied to the original water supply output for the level one upgrade.
};

#endif // WATERSUPPLYLEVELONEUPGRADE_H
