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
    WaterSupplyLevelThreeUpgrade(WaterSupply* water);

    /**
     * @brief Copy constructor for WaterSupplyLevelThreeUpgrade.
     * 
     * Creates a new WaterSupplyLevelThreeUpgrade object by copying the attributes of an existing
     * WaterSupplyLevelThreeUpgrade object.
     * 
     * @param waterSupplyLevelThreeUpgrade Pointer to the existing WaterSupplyLevelThreeUpgrade to be copied.
     */
    WaterSupplyLevelThreeUpgrade(WaterSupplyLevelThreeUpgrade* waterSupplyLevelThreeUpgrade);

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
    void update();

    /**
     * @brief Clones the current WaterSupplyLevelThreeUpgrade object.
     * 
     * Creates a new instance of WaterSupplyLevelThreeUpgrade with the same attributes as the current object.
     * 
     * @return A pointer to the newly cloned WaterSupplyLevelThreeUpgrade object.
     */
    Entity* clone();

    Entity* upgrade();

    /**
     * @brief Retrieves the upgraded water supply system's output.
     * 
     * Returns the delivery capacity of the level three upgraded water supply system.
     * 
     * @return The updated delivery capacity as an integer.
     */
    int getOutput();

    Cost getCost();

private:
    const int UPGRADE = 6; ///< Multiplier applied to the original delivery capacity for the level three upgrade.
};

#endif // WATERSUPPLYLEVELTHREEUPGRADE_H
