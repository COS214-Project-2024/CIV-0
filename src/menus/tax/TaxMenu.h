/**
 * @file TaxMenu.h
 * @brief Declares the TaxMenu class for managing tax adjustments in the game.
 */

#ifndef TAXMENU_H
#define TAXMENU_H

#include "menus/base/IMenu.h"

/**
 * @class TaxMenu
 * @brief Provides functionality for managing and adjusting tax rates in the game.
 *
 * The TaxMenu class allows players to increase or decrease economic and residential tax rates
 * through user-friendly menu interactions.
 */
class TaxMenu : public IMenu
{
public:
    /**
     * @brief Constructs a TaxMenu object.
     *
     * Initializes the TaxMenu with options for adjusting tax rates and navigation.
     */
    TaxMenu();

    /**
     * @brief Destructor for TaxMenu.
     *
     * Cleans up resources used by the TaxMenu.
     */
    ~TaxMenu();

    /**
     * @brief Displays the tax management menu.
     *
     * Overrides the display method from IMenu to present tax adjustment options.
     */
    void display() const override;

    /**
     * @brief Handles user input for the Tax menu.
     *
     * Processes user selections to increase or decrease economic and residential taxes,
     * and navigates back to the main menu as needed.
     */
    void handleInput() override;
};

#endif // TAXMENU_H
