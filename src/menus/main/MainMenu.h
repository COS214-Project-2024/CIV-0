/**
 * @file MainMenu.h
 * @brief Defines the MainMenu class, representing the main interface of the game.
 */

#ifndef MAINMENU_H
#define MAINMENU_H

#include "menus/base/IMenu.h"

/**
 * @class MainMenu
 * @brief Represents the main menu of the game, providing primary navigation options.
 *
 * The MainMenu class offers the player key interactions, such as accessing sub-menus for buildings,
 * upgrades, policies, taxes, city stats, and the option to quit the game.
 */
class MainMenu : public IMenu
{
public:
    /**
     * @brief Constructs the MainMenu.
     *
     * Initializes the menu with various sections and options for player interaction.
     */
    MainMenu();

    /**
     * @brief Destructor for MainMenu.
     *
     * Cleans up resources used by the MainMenu instance.
     */
    ~MainMenu();

    /**
     * @brief Displays the MainMenu.
     *
     * Overrides the display method from IMenu to render the main menu interface.
     */
    void display() const override;

    /**
     * @brief Handles user input in the MainMenu.
     *
     * Processes user selections to navigate to other menus or exit the game.
     * This method listens for input, validates it, and triggers corresponding actions.
     */
    void handleInput() override;
};

#endif // MAINMENU_H
