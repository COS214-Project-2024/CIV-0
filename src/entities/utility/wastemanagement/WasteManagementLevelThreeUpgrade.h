#ifndef WASTEMANAGEMENTLEVELTHREEUPGRADE_H
#define WASTEMANAGEMENTLEVELTHREEUPGRADE_H

#include "WasteManagementUpgrade.h"

/**
 * @class WasteManagementLevelThreeUpgrade
 * @brief Represents the third level upgrade to a WasteManagement entity.
 *
 * The WasteManagementLevelThreeUpgrade class enhances the base functionality of a WasteManagement system by increasing
 * its efficiency. This class is the third upgrade level in a series of potential waste management improvements.
 */
class WasteManagementLevelThreeUpgrade : public WasteManagementUpgrade
{
public:
    /**
     * @brief Constructs a WasteManagementLevelThreeUpgrade object.
     *
     * Initializes the upgrade by enhancing the specified WasteManagement with a level three upgrade.
     *
     * @param waste Pointer to the original WasteManagement to be upgraded.
     */
    WasteManagementLevelThreeUpgrade(WasteManagement *waste);

    /**
     * @brief Copy constructor for WasteManagementLevelThreeUpgrade.
     *
     * Creates a new WasteManagementLevelThreeUpgrade object by copying the attributes of an existing
     * WasteManagementLevelThreeUpgrade object.
     *
     * @param wasteManagementLevelThreeUpgrade Pointer to the existing WasteManagementLevelThreeUpgrade to be copied.
     */
    WasteManagementLevelThreeUpgrade(WasteManagementLevelThreeUpgrade *wasteManagementLevelThreeUpgrade);

    /**
     * @brief Destructor for WasteManagementLevelThreeUpgrade.
     *
     * Cleans up any resources associated with the upgrade.
     */
    ~WasteManagementLevelThreeUpgrade();

    /**
     * @brief Updates the state of the upgraded waste management system.
     *
     * Implements specific behavior for the waste management system after applying the level three upgrade.
     */
    void update() override;

    /**
     * @brief Clones the current WasteManagementLevelThreeUpgrade object.
     *
     * Creates a new instance of WasteManagementLevelThreeUpgrade with the same attributes as the current object.
     *
     * @return A pointer to the newly cloned WasteManagementLevelThreeUpgrade object.
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
     * Returns the efficiency output of the level three upgraded waste management system.
     *
     * @return The updated efficiency output as an integer.
     */
    int getOutput() override;

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    Cost getCost() override;

    int getLevel() override;

private:
    const int UPGRADE = 6; ///< Multiplier applied to the original efficiency output for the level three upgrade.
};

#endif // WASTEMANAGEMENTLEVELTHREEUPGRADE_H
