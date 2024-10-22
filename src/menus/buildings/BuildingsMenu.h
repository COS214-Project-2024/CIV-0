#ifndef BUILDINGSMENU_H
#define BUILDINGSMENU_H

#include <vector>
#include "menus/base/IMenu.h"
#include "utils/EntityType.h"

/**
 * @brief Represents the menu for managing buildings in the game.
 * This menu provides options for buying, selling, and viewing stats of buildings.
 */
class BuildingsMenu : public IMenu
{
public:
    /**
     * @brief Constructor for BuildingsMenu.
     * Initializes the menu sections with various building management options.
     */
    BuildingsMenu();

    /**
     * @brief Destructor for BuildingsMenu.
     */
    ~BuildingsMenu();

    /**
     * @brief Displays the Buildings menu.
     * Calls the inherited displayMenu() function to render the menu to the user.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Buildings menu.
     * Processes input based on user choices and updates the current menu accordingly.
     */
    void handleInput() override;
};

#endif // BUILDINGSMENU_H
