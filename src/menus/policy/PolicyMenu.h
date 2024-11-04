/**
 * @file PolicyMenu.h
 * @brief Declares the PolicyMenu class for managing policy-related interactions in the game.
 */

#ifndef POLICYMENU_H
#define POLICYMENU_H

#include "menus/base/IMenu.h"
#include "managers/GovernmentManager.h"
#include <vector>
#include <string>

/**
 * @class PolicyMenu
 * @brief Provides functionality for players to apply and review city policies.
 *
 * The PolicyMenu class allows players to choose new water and electricity policies, and view
 * the history of all previously applied policies.
 */
class PolicyMenu : public IMenu
{
public:
    /**
     * @brief Constructs the PolicyMenu.
     *
     * Initializes the PolicyMenu instance with options for applying new policies and viewing history.
     */
    PolicyMenu();

    /**
     * @brief Destructor for PolicyMenu.
     *
     * Cleans up resources used by the PolicyMenu.
     */
    ~PolicyMenu();

    /**
     * @brief Displays the Policy Menu.
     *
     * Overrides the display method of IMenu to render the policy options.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Policy Menu.
     *
     * Processes input to navigate between policy options and apply new policies.
     */
    void handleInput() override;

private:
    GovernmentManager governmentManager; ///< Manages policy-related actions and history.

    /**
     * @brief Submenu to select a water consumption policy.
     *
     * Presents options for high, normal, or low water consumption policies and applies the chosen policy.
     */
    void selectWaterPolicy();

    /**
     * @brief Submenu to select an electricity consumption policy.
     *
     * Presents options for high, normal, or low electricity consumption policies and applies the chosen policy.
     */
    void selectElectricityPolicy();

    /**
     * @brief Displays the history of all applied policies.
     *
     * Shows a list of past policies enacted in the city, formatted for user review.
     */
    void showPolicyHistory();
};

#endif // POLICYMENU_H
