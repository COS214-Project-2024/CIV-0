#ifndef POLICYMENU_H
#define POLICYMENU_H

#include "menus/base/IMenu.h"
#include "managers/GovernmentManager.h"
#include <vector>
#include <string>

class PolicyMenu : public IMenu
{
public:
    PolicyMenu();
    ~PolicyMenu();

    /**
     * @brief Displays the Policy Menu.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Policy Menu.
     */
    void handleInput() override;

private:
    GovernmentManager governmentManager;

    /**
     * @brief Submenu to select water consumption policy.
     */
    void selectWaterPolicy();

    /**
     * @brief Submenu to select electricity consumption policy.
     */
    void selectElectricityPolicy();

    /**
     * @brief Displays the history of all applied policies.
     */
    void showPolicyHistory();
};

#endif // POLICYMENU_H
