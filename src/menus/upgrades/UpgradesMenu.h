#ifndef UPGRADESMENU_H
#define UPGRADESMENU_H

#include "menus/base/IMenu.h"

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
};

#endif // UPGRADESMENU_H
