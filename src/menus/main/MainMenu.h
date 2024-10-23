#ifndef MAINMENU_H
#define MAINMENU_H

#include "menus/base/IMenu.h"

/**
 * @brief Represents the main menu of the game.
 *
 * This class defines the main options available for the player to interact with,
 * including accessing the buildings menu, upgrades, policies, taxes, city stats,
 * and quitting the game.
 */
class MainMenu : public IMenu
{
public:
    /**
     * @brief Constructor for MainMenu.
     * Initializes the main menu and sets up the various sections and options.
     */
    MainMenu();

    /**
     * @brief Destructor for MainMenu.
     */
    ~MainMenu();

    /**
     * @brief Displays the Main menu.
     * This function overrides the display() function of IMenu to render the main options.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Main menu.
     * Allows the user to navigate between different menus and exit the game.
     */
    void handleInput() override;
};

#endif // MAINMENU_H
