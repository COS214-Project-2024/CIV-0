#ifndef SELLMENU_H
#define SELLMENU_H

#include "menus/base/IMenu.h"
#include <vector>

/**
 * @brief Menu for selling buildings in the game.
 * Provides options to sell a specific building or sell all buildings of a particular type.
 */
class SellMenu : public IMenu
{
public:
    /**
     * @brief Constructor for SellMenu.
     */
    SellMenu();

    /**
     * @brief Destructor for SellMenu.
     */
    ~SellMenu();

    /**
     * @brief Displays the sell menu.
     */
    void display() const override;

    /**
     * @brief Handles user input for the sell menu.
     */
    void handleInput() override;

private:
    /**
     * @brief Presents a menu for selling a specific building.
     */
    void sellSpecificBuilding();

    /**
     * @brief Presents a menu for selecting and selling all buildings of a particular type.
     */
    void sellAllBuildingsOfType();

    /**
     * @brief Helper function to confirm the sale of buildings.
     * @param buildingsToSell A list of buildings the user is about to sell.
     */
    void confirmSell(const std::vector<std::string> &buildingsToSell);
};

#endif // SELLMENU_H
