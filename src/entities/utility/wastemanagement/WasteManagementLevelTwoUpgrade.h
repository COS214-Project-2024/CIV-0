#ifndef WASTEMANAGEMENTLEVELTWOUPGRADE_H
#define WASTEMANAGEMENTLEVELTWOUPGRADE_H

#include "WasteManagementUpgrade.h"

class WasteManagementLevelThreeUpgrade;

/**
 * @class WasteManagementLevelTwoUpgrade
 * @brief Represents the second level upgrade to a WasteManagement entity.
 *
 * The WasteManagementLevelTwoUpgrade class enhances the base functionality of a WasteManagement system by
 * increasing its output. This is the second upgrade level in the series.
 */
class WasteManagementLevelTwoUpgrade : public WasteManagementUpgrade
{
public:
    /**
     * @brief Constructs a WasteManagementLevelTwoUpgrade object.
     *
     * Enhances the specified WasteManagement system with a level two upgrade.
     *
     * @param waste Pointer to the original WasteManagement to be upgraded.
     */
    WasteManagementLevelTwoUpgrade(WasteManagement *waste);

    /**
     * @brief Copy constructor for WasteManagementLevelTwoUpgrade.
     *
     * Copies the attributes of an existing WasteManagementLevelTwoUpgrade object.
     * 
     * @param wMLTU Pointer to the existing object to be copied.
     */
    WasteManagementLevelTwoUpgrade(WasteManagementLevelTwoUpgrade *wMLTU);

    /**
     * @brief Destructor for WasteManagementLevelTwoUpgrade.
     */
    ~WasteManagementLevelTwoUpgrade();

    /**
     * @brief Updates the state of the upgraded waste management system.
     */
    void update() override;

    /**
     * @brief Clones the current WasteManagementLevelTwoUpgrade object.
     *
     * @return A pointer to the newly cloned object.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade() override;

    /**
     * @brief Retrieves the upgraded waste management system's output.
     *
     * Returns the output of the level one upgraded waste management system.
     *
     * @return The updated output as an integer.
     */
    int getOutput() override;

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    Cost getCost() override;

    int getLevel() override;

private:
    const int UPGRADE = 4; ///< Output multiplier for the level two upgrade.
};

#endif // WASTEMANAGEMENTLEVELTWOUPGRADE_H
