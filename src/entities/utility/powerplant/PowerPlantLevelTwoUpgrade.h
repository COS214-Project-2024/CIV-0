#ifndef POWERPLANTLEVELTWOUPGRADE_H
#define POWERPLANTLEVELTWOUPGRADE_H

#include "PowerPlantUpgrade.h"

/**
 * @class PowerPlantLevelTwoUpgrade
 * @brief Represents the second level upgrade to a PowerPlant entity.
 *
 * The PowerPlantLevelTwoUpgrade class enhances the base functionality of a PowerPlant by increasing
 * its output. This class is the second upgrade level in a series of potential power plant improvements.
 */
class PowerPlantLevelTwoUpgrade : public PowerPlantUpgrade
{
public:
    /**
     * @brief Constructs a PowerPlantLevelTwoUpgrade object.
     * 
     * Initializes the upgrade by enhancing the specified PowerPlant with a level two upgrade.
     * 
     * @param powerPlant Pointer to the original PowerPlant to be upgraded.
     */
    PowerPlantLevelTwoUpgrade(PowerPlant* powerPlant);

    /**
     * @brief Copy constructor for PowerPlantLevelTwoUpgrade.
     * 
     * Creates a new PowerPlantLevelTwoUpgrade object by copying the attributes of an existing
     * PowerPlantLevelTwoUpgrade object.
     * 
     * @param powerPlantLevelTwoUpgrade Pointer to the existing PowerPlantLevelTwoUpgrade to be copied.
     */
    PowerPlantLevelTwoUpgrade(PowerPlantLevelTwoUpgrade* powerPlantLevelTwoUpgrade);

    /**
     * @brief Destructor for PowerPlantLevelTwoUpgrade.
     * 
     * Cleans up any resources associated with the upgrade.
     */
    ~PowerPlantLevelTwoUpgrade();

    /**
     * @brief Updates the state of the upgraded power plant.
     * 
     * Implements specific behavior for the power plant after applying the level two upgrade.
     */
    void update();

    /**
     * @brief Clones the current PowerPlantLevelTwoUpgrade object.
     * 
     * Creates a new instance of PowerPlantLevelTwoUpgrade with the same attributes as the current object.
     * 
     * @return A pointer to the newly cloned PowerPlantLevelTwoUpgrade object.
     */
    Entity* clone();

    /**
     * @brief Retrieves the upgraded power plant's output.
     * 
     * Returns the power output of the level two upgraded power plant.
     * 
     * @return The updated power output as an integer.
     */
    int getOutput();

private:
    const int UPGRADE = 4; ///< Multiplier applied to the original power output for the level two upgrade.
};

#endif // POWERPLANTLEVELTWOUPGRADE_H
