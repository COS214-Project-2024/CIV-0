#ifndef POLICYMENU_H
#define POLICYMENU_H

#include "menus/base/IMenu.h"

/**
 * @brief Represents the menu for managing policies in the game.
 */
class PolicyMenu : public IMenu
{
public:
    /**
     * @brief Constructor for PolicyMenu.
     */
    PolicyMenu();

    /**
     * @brief Destructor for PolicyMenu.
     */
    ~PolicyMenu();

    /**
     * @brief Displays the Policy menu.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Policy menu.
     */
    void handleInput() override;
};

#endif // POLICYMENU_H
