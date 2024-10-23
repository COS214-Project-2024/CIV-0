#ifndef POLICYMENU_H
#define POLICYMENU_H

#include "menus/base/IMenu.h"
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
    std::vector<std::string> policyHistory; ///< Stores all past policy applications

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

    /**
     * @brief Records a new policy in the history.
     * @param policyDescription The description of the policy.
     */
    void addPolicyToHistory(std::string policyDescription);
};

#endif // POLICYMENU_H
