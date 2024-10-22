#ifndef TAXMENU_H
#define TAXMENU_H

#include "menus/base/IMenu.h"

/**
 * @brief Represents the menu for managing taxes in the game.
 */
class TaxMenu : public IMenu
{
public:
    /**
     * @brief Constructor for TaxMenu.
     */
    TaxMenu();

    /**
     * @brief Destructor for TaxMenu.
     */
    ~TaxMenu();

    /**
     * @brief Displays the Tax menu.
     */
    void display() const override;

    /**
     * @brief Handles user input in the Tax menu.
     */
    void handleInput() override;
};

#endif // TAXMENU_H
