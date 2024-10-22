#ifndef WATERSUPPLYLEVELTWOUPGRADE_H
#define WATERSUPPLYLEVELTWOUPGRADE_H

#include "WaterSupplyUpgrade.h"

/**
 * @class WaterSupplyLevelTwoUpgrade
 * @brief Represents the second level upgrade to a WaterSupply entity.
 *
 * The WaterSupplyLevelTwoUpgrade class enhances the base functionality of a WaterSupply system by
 * increasing its output. This class represents the second upgrade level in the series.
 */
class WaterSupplyLevelTwoUpgrade : public WaterSupplyUpgrade
{
public:
    /**
     * @brief Constructs a WaterSupplyLevelTwoUpgrade object.
     * 
     * Enhances the specified WaterSupply system with a level two upgrade.
     * 
     * @param waterSupply Pointer to the original WaterSupply to be upgraded.
     */
    WaterSupplyLevelTwoUpgrade(WaterSupply* waterSupply);

    /**
     * @brief Copy constructor for WaterSupplyLevelTwoUpgrade.
     * 
     * Copies the attributes of an existing WaterSupplyLevelTwoUpgrade object.
     * 
     * @param waterSupplyLevelTwoUpgrade Pointer to the existing object to be copied.
     */
    WaterSupplyLevelTwoUpgrade(WaterSupplyLevelTwoUpgrade* waterSupplyLevelTwoUpgrade);

    /**
     * @brief Destructor for WaterSupplyLevelTwoUpgrade.
     */
    ~WaterSupplyLevelTwoUpgrade();

    /**
     * @brief Updates the state of the upgraded water supply system.
     */
    void update();

    /**
     * @brief Clones the current WaterSupplyLevelTwoUpgrade object.
     * 
     * @return A pointer to the newly cloned object.
     */
    Entity* clone();

    /**
     * @brief Retrieves the upgraded water supply system's output.
     * 
     * Returns the output of the level one upgraded water supply system.
     * 
     * @return The updated output as an integer.
     */
    int getOutput();

private:
    const int UPGRADE = 4; ///< Output multiplier for the level two upgrade.
};

#endif // WATERSUPPLYLEVELTWOUPGRADE_H
