/**
 * @file BuildingsMenu.h
 * @brief Declares the BuildingsMenu class for managing building-related options in the game.
 */

#ifndef BUILDINGSMENU_H
#define BUILDINGSMENU_H

#include <vector>
#include "menus/base/IMenu.h"
#include "utils/EntityType.h"

/**
 * @class BuildingsMenu
 * @brief Provides a menu interface for managing buildings in the game.
 *
 * The BuildingsMenu class allows players to buy, sell, and view statistics
 * for different types of buildings. It includes methods for displaying the
 * menu, handling user input, and navigating to relevant submenus or actions.
 */
class BuildingsMenu : public IMenu
{
public:
    /**
     * @brief Constructs a BuildingsMenu object.
     *
     * Initializes the menu sections with options for buying, demolishing,
     * and viewing building statistics.
     */
    BuildingsMenu();

    /**
     * @brief Destructor for BuildingsMenu.
     *
     * Cleans up any resources or memory used by the BuildingsMenu.
     */
    ~BuildingsMenu();

    /**
     * @brief Displays the Buildings menu.
     *
     * Overrides the display method from IMenu to render the menu options
     * and sections to the user.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Buildings menu.
     *
     * Processes the user's input to navigate through different options
     * for buying, selling, or viewing building statistics, updating the
     * current menu as needed.
     */
    void handleInput() override;
};

#endif // BUILDINGSMENU_H