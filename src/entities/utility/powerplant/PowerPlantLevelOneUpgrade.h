#ifndef POWERPLANTLEVELONEUPGRADE_H
#define POWERPLANTLEVELONEUPGRADE_H

#include "PowerPlantUpgrade.h"

class PowerPlantLevelTwo;

/**
 * @class PowerPlantLevelOneUpgrade
 * @brief Represents the first level upgrade to a PowerPlant entity.
 *
 * The PowerPlantLevelOneUpgrade class enhances the base functionality of a PowerPlant by increasing
 * its output. This class is the first upgrade level in a series of potential power plant improvements.
 */
class PowerPlantLevelOneUpgrade : public PowerPlantUpgrade
{
public:
    /**
     * @brief Constructs a PowerPlantLevelOneUpgrade object.
     *
     * Initializes the upgrade by enhancing the specified PowerPlant with a level one upgrade.
     *
     * @param power Pointer to the original PowerPlant to be upgraded.
     */
    PowerPlantLevelOneUpgrade(PowerPlant *power);

    /**
     * @brief Copy constructor for PowerPlantLevelOneUpgrade.
     *
     * Creates a new PowerPlantLevelOneUpgrade object by copying the attributes of an existing
     * PowerPlantLevelOneUpgrade object.
     * 
     * @param pPLOU Pointer to the existing PowerPlantLevelOneUpgrade to be copied.
     */
    PowerPlantLevelOneUpgrade(PowerPlantLevelOneUpgrade *pPLOU);

    /**
     * @brief Destructor for PowerPlantLevelOneUpgrade.
     *
     * Cleans up any resources associated with the upgrade.
     */
    ~PowerPlantLevelOneUpgrade();

    /**
     * @brief Updates the state of the upgraded power plant.
     *
     * Implements specific behavior for the power plant after applying the level one upgrade.
     */
    void update() override;

    /**
     * @brief Clones the current PowerPlantLevelOneUpgrade object.
     *
     * Creates a new instance of PowerPlantLevelOneUpgrade with the same attributes as the current object.
     *
     * @return A pointer to the newly cloned PowerPlantLevelOneUpgrade object.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade() override;

    /**
     * @brief Retrieves the upgraded power plant's output.
     *
     * Returns the power output of the level one upgraded power plant.
     *
     * @return The updated power output as an integer.
     */
    int getOutput() override;

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    Cost getCost() override;

    /**
     * @brief Gets the level of the power plant upgrade.
     *
     * @return The level of the power plant upgrade.
     */
    int getLevel() override;

private:
    const int UPGRADE = 2; ///< Multiplier applied to the original power output for the level one upgrade.
};

#endif // POWERPLANTLEVELONEUPGRADE_H
