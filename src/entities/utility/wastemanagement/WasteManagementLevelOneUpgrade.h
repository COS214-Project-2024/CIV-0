#ifndef WASTEMANAGEMENTLEVELONEUPGRADE_H
#define WASTEMANAGEMENTLEVELONEUPGRADE_H

#include "WasteManagementUpgrade.h"

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
     * @param wasteManagement Pointer to the original WasteManagement to be upgraded.
     */
    WasteManagementLevelOneUpgrade(WasteManagement* wasteManagement);

    /**
     * @brief Copy constructor for WasteManagementLevelOneUpgrade.
     * 
     * Creates a new WasteManagementLevelOneUpgrade object by copying the attributes of an existing
     * WasteManagementLevelOneUpgrade object.
     * 
     * @param wasteManagementLevelOneUpgrade Pointer to the existing WasteManagementLevelOneUpgrade to be copied.
     */
    WasteManagementLevelOneUpgrade(WasteManagementLevelOneUpgrade* wasteManagementLevelOneUpgrade);

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
     * @brief Retrieves the upgraded waste management system's output.
     * 
     * Returns the output of the level one upgraded waste management system, which reflects a 1.5x enhancement.
     * 
     * @return The updated output as an integer.
     */
    int getOutput();

private:
    const int UPGRADE = 1.5; ///< Multiplier applied to the original waste management output for the level one upgrade.
};

#endif // WASTEMANAGEMENTLEVELONEUPGRADE_H
