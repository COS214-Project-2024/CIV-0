#ifndef WASTEMANAGEMENTLEVELTWOUPGRADE_H
#define WASTEMANAGEMENTLEVELTWOUPGRADE_H

#include "WasteManagementUpgrade.h"

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
     * @param wasteManagement Pointer to the original WasteManagement to be upgraded.
     */
    WasteManagementLevelTwoUpgrade(WasteManagement* wasteManagement);

    /**
     * @brief Copy constructor for WasteManagementLevelTwoUpgrade.
     * 
     * Copies the attributes of an existing WasteManagementLevelTwoUpgrade object.
     * 
     * @param wasteManagementLevelTwoUpgrade Pointer to the existing object to be copied.
     */
    WasteManagementLevelTwoUpgrade(WasteManagementLevelTwoUpgrade* wasteManagementLevelTwoUpgrade);

    /**
     * @brief Destructor for WasteManagementLevelTwoUpgrade.
     */
    ~WasteManagementLevelTwoUpgrade();

    /**
     * @brief Updates the state of the upgraded waste management system.
     */
    void update();

    /**
     * @brief Clones the current WasteManagementLevelTwoUpgrade object.
     * 
     * @return A pointer to the newly cloned object.
     */
    Entity* clone();

    /**
     * @brief Retrieves the upgraded waste management system's output.
     * 
     * @return The updated output with a 2.625x enhancement.
     */
    int getOutput();

private:
    const int UPGRADE = 2.625; ///< Output multiplier for the level two upgrade.
};

#endif // WASTEMANAGEMENTLEVELTWOUPGRADE_H
