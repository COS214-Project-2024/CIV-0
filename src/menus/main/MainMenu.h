#ifndef MAINMENU_H
#define MAINMENU_H

#include "menus/base/IMenu.h"

/**
 * @brief Represents the main menu of the game.
 */
class MainMenu : public IMenu
{
public:
    /**
     * @brief Constructor for MainMenu.
     */
    MainMenu();

    /**
     * @brief Destructor for MainMenu.
     */
    ~MainMenu();

    /**
     * @brief Displays the Main menu.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Main menu.
     */
    void handleInput() const override;
};

#endif // MAINMENU_H
