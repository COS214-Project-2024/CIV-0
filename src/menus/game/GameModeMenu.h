#ifndef GAMEMODEMENU_H
#define GAMEMODEMENU_H

#include "menus/base/IMenu.h"

/**
 * @class GameModeMenu
 * @brief Menu for selecting the game mode at startup.
 */
class GameModeMenu : public IMenu
{
public:
    /**
     * @brief Constructor for GameModeMenu.
     */
    GameModeMenu();

    /**
     * @brief Destructor for GameModeMenu.
     */
    ~GameModeMenu();

    /**
     * @brief Displays the menu to the user.
     */
    void display() const override;

    /**
     * @brief Handles user input for the menu.
     */
    void handleInput() override;
};

#endif // GAMEMODEMENU_H
