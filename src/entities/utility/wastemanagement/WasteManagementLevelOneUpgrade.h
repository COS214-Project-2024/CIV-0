#ifndef WASTEMANAGEMENTLEVELONEUPGRADE_H
#define WASTEMANAGEMENTLEVELONEUPGRADE_H

#include "WasteManagementUpgrade.h"

class WasteManagementLevelTwoUpgrade;

/**
 * @class WasteManagementLevelOneUpgrade
 * @brief Represents the first level upgrade to a WasteManagement entity.
 *
 * The WasteManagementLevelOneUpgrade class enhances the base functionality of a WasteManagement by increasing
 * its output. This class is the first upgrade level in a series of potential waste management improvements.
 */
class WasteManagementLevelOneUpgrade : public WasteManagementUpgrade
{
public:
    /**
     * @brief Constructs a WasteManagementLevelOneUpgrade object.
     * 
     * Initializes the upgrade by enhancing the specified WasteManagement with a level one upgrade.
     * 
     * @param waste Pointer to the original WasteManagement to be upgraded.
     */
    WasteManagementLevelOneUpgrade(WasteManagement* waste);

    /**
     * @brief Copy constructor for WasteManagementLevelOneUpgrade.
     * 
     * Creates a new WasteManagementLevelOneUpgrade object by copying the attributes of an existing
     * WasteManagementLevelOneUpgrade object.
     * 
     * @param wMLOU Pointer to the existing WasteManagementLevelOneUpgrade to be copied.
     */
    WasteManagementLevelOneUpgrade(WasteManagementLevelOneUpgrade* wMLOU);

    /**
     * @brief Destructor for WasteManagementLevelOneUpgrade.
     * 
     * Cleans up any resources associated with the upgrade.
     */
    ~WasteManagementLevelOneUpgrade();

    /**
     * @brief Updates the state of the upgraded waste management system.
     * 
     * Implements specific behavior for the waste management system after applying the level one upgrade.
     */
    void update();

    /**
     * @brief Clones the current WasteManagementLevelOneUpgrade object.
     * 
     * Creates a new instance of WasteManagementLevelOneUpgrade with the same attributes as the current object.
     * 
     * @return A pointer to the newly cloned WasteManagementLevelOneUpgrade object.
     */
    Entity* clone();

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity* upgrade();

    /**
     * @brief Retrieves the upgraded waste management system's output.
     * 
     * Returns the output of the level one upgraded waste management system.
     * 
     * @return The updated output as an integer.
     */
    int getOutput();

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    Cost getCost();

private:
    const int UPGRADE = 2; ///< Multiplier applied to the original waste management output for the level one upgrade.
};

#endif // WASTEMANAGEMENTLEVELONEUPGRADE_H
