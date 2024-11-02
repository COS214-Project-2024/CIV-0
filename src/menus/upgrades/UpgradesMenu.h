/**
 * @file UpgradesMenu.h
 * @brief Declares the UpgradesMenu class for upgrading various systems in the game.
 */

#ifndef UPGRADESMENU_H
#define UPGRADESMENU_H

#include "menus/base/IMenu.h"
#include "managers/UtilityManager.h"
#include "managers/ResourceManager.h"
#include <vector>

/**
 * @class UpgradesMenu
 * @brief Provides a menu interface for upgrading utilities and industries in the game.
 *
 * The UpgradesMenu class enables players to navigate and select upgrade options for various
 * game systems, such as utilities and industries. It includes methods to display
 * the menu, handle user input, and confirm specific upgrades.
 */
class UpgradesMenu : public IMenu
{
public:
    /**
     * @brief Constructs an UpgradesMenu object.
     *
     * Initializes the menu options for upgrading utilities and industries.
     */
    UpgradesMenu();

    /**
     * @brief Destructor for UpgradesMenu.
     *
     * Cleans up resources used by the UpgradesMenu.
     */
    ~UpgradesMenu();

    /**
     * @brief Displays the upgrade options menu.
     *
     * Overrides the display method from IMenu to present the upgrade categories to the user.
     */
    void display() const override;

    /**
     * @brief Handles user input for the Upgrades menu.
     *
     * Processes user selections to navigate through the upgrade options and confirms choices.
     */
    void handleInput() override;

private:
    /**
     * @brief Displays and handles input for upgrading utilities.
     *
     * Allows the player to choose a specific utility to upgrade from available options.
     */
    void upgradeUtilities();

    /**
     * @brief Displays and handles input for upgrading industries.
     *
     * Provides the player with a selection of industries to upgrade.
     */
    void upgradeIndustries();

    /**
     * @brief Allows the user to select a specific utility for upgrade.
     *
     * @param type The type of utility being upgraded (e.g., "Power Plant").
     * @param options A vector of pointers to available utility instances.
     */
    void selectSpecificUtility(const std::string &type, const std::vector<Utility *> &options);

    /**
     * @brief Allows the user to select a specific industry for upgrade.
     *
     * @param type The type of industry being upgraded (e.g., "Concrete Producer").
     * @param options A vector of pointers to available industry instances.
     */
    void selectSpecificIndustry(const std::string &type, const std::vector<Industry *> &options);

    /**
     * @brief Confirms and processes an upgrade for a specific entity.
     *
     * @param entityName The name of the entity to upgrade.
     * @param currentLevel The current level of the entity.
     * @param upgradeCost The cost required to upgrade the entity to the next level.
     */
    void confirmUpgrade(const std::string &entityName, int currentLevel, int upgradeCost);

private:
    UtilityManager utilityManager;   ///< Manages utility-related operations for upgrades.
    ResourceManager resourceManager; ///< Manages resource-related operations for industry upgrades.
};

#endif // UPGRADESMENU_H