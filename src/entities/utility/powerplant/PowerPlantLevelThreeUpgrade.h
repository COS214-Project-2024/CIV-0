#ifndef POWERPLANTLEVELTHREEUPGRADE_H
#define POWERPLANTLEVELTHREEUPGRADE_H

#include "PowerPlantUpgrade.h"

/**
 * @class PowerPlantLevelThreeUpgrade
 * @brief Represents the third level upgrade to a PowerPlant entity.
 *
 * The PowerPlantLevelThreeUpgrade class enhances the base functionality of a PowerPlant by increasing
 * its output. This class is the third upgrade level in a series of potential power plant improvements.
 */
class PowerPlantLevelThreeUpgrade : public PowerPlantUpgrade
{
public:
    /**
     * @brief Constructs a PowerPlantLevelThreeUpgrade object.
     *
     * Initializes the upgrade by enhancing the specified PowerPlant with a level three upgrade.
     *
     * @param power Pointer to the original PowerPlant to be upgraded.
     */
    PowerPlantLevelThreeUpgrade(PowerPlant *power);

    /**
     * @brief Copy constructor for PowerPlantLevelThreeUpgrade.
     *
     * Creates a new PowerPlantLevelThreeUpgrade object by copying the attributes of an existing
     * PowerPlantLevelThreeUpgrade object.
     * 
     * @param pPLTU Pointer to the existing PowerPlantLevelThreeUpgrade to be copied.
     */
    PowerPlantLevelThreeUpgrade(PowerPlantLevelThreeUpgrade *pPLTU);

    /**
     * @brief Destructor for PowerPlantLevelThreeUpgrade.
     *
     * Cleans up any resources associated with the upgrade.
     */
    ~PowerPlantLevelThreeUpgrade();

    /**
     * @brief Updates the state of the upgraded power plant.
     *
     * Implements specific behavior for the power plant after applying the level three upgrade.
     */
    void update();

    /**
     * @brief Clones the current PowerPlantLevelThreeUpgrade object.
     *
     * Creates a new instance of PowerPlantLevelThreeUpgrade with the same attributes as the current object.
     *
     * @return A pointer to the newly cloned PowerPlantLevelThreeUpgrade object.
     */
    Entity *clone();

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade();

    /**
     * @brief Retrieves the upgraded power plant's output.
     *
     * Returns the power output of the level three upgraded power plant.
     *
     * @return The updated power output as an integer.
     */
    int getOutput();

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    Cost getCost();

    int getLevel() override;

private:
    const int UPGRADE = 6; ///< Multiplier applied to the original power output for the level three upgrade.
};

#endif // POWERPLANTLEVELTHREEUPGRADE_H
