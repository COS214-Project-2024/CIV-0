#ifndef UPGRADESMENU_H
#define UPGRADESMENU_H

#include "menus/base/IMenu.h"
#include "managers/UtilityManager.h"
#include <vector>

/**
 * @brief Represents the menu for upgrading various systems in the game.
 */
class UpgradesMenu : public IMenu
{
public:
    /**
     * @brief Constructor for UpgradesMenu.
     */
    UpgradesMenu();

    /**
     * @brief Destructor for UpgradesMenu.
     */
    ~UpgradesMenu();

    /**
     * @brief Displays the Upgrades menu.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Upgrades menu.
     */
    void handleInput() override;

private:
    /**
     * @brief Submenu for upgrading utilities.
     */
    void upgradeUtilities();

    /**
     * @brief Submenu for upgrading industries.
     */
    void upgradeIndustries();

    /**
     * @brief Submenu to select a specific utility or industry to upgrade.
     * @param type The name of the utility or industry (e.g., "Water Supply").
     * @param options The list of available options for that utility or industry.
     */
    void selectSpecificUtilityOrIndustry(const std::string &type, const std::vector<Utility *> &options);

    /**
     * @brief Handles upgrading a specific entity by showing current level, upgrade cost, and asking for confirmation.
     * @param entityName The name of the entity to upgrade.
     * @param currentLevel The current level of the entity.
     * @param upgradeCost The cost to upgrade to the next level.
     */
    void confirmUpgrade(const std::string &entityName, int currentLevel, int upgradeCost);

private:
    UtilityManager utilityManager;
};

#endif // UPGRADESMENU_H
