#ifndef BUILDINGSMENU_H
#define BUILDINGSMENU_H

#include "menus/base/IMenu.h"

/**
 * @brief Represents the menu for managing buildings in the game.
 */
class BuildingsMenu : public IMenu
{
public:
    /**
     * @brief Constructor for BuildingsMenu.
     */
    BuildingsMenu();

    /**
     * @brief Destructor for BuildingsMenu.
     */
    ~BuildingsMenu();

    /**
     * @brief Displays the Buildings menu.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Buildings menu.
     */
    void handleInput() override;
};

#endif // BUILDINGSMENU_H
