/**
 * @file BuyRoadMenu.h
 * @brief Declares the BuyRoadMenu class for managing road purchases in the game.
 */

#ifndef BUYROADMENU_H
#define BUYROADMENU_H

#include "menus/base/IMenu.h"
#include "managers/TransportManager.h"

/**
 * @class BuyRoadMenu
 * @brief Provides functionality for players to purchase roads and place them in the city.
 *
 * The BuyRoadMenu class allows users to select positions in the city to place new roads,
 * confirm their purchase, and handle related input and display operations.
 */
class BuyRoadMenu : public IMenu
{
public:
    /**
     * @brief Constructs the BuyRoadMenu.
     *
     * Initializes the menu with relevant sections and headings.
     */
    BuyRoadMenu();

    /**
     * @brief Destructor for BuyRoadMenu.
     *
     * Cleans up resources used by the BuyRoadMenu.
     */
    virtual ~BuyRoadMenu();

    /**
     * @brief Displays the road buying menu.
     *
     * Overrides the display method of IMenu to render the road purchase interface.
     */
    void display() const override;

    /**
     * @brief Handles user input for selecting a position and confirming road purchase.
     *
     * Processes input to guide users through selecting positions for roads and finalizing their purchase.
     */
    void handleInput() override;

private:
    TransportManager transportManager; ///< Manages operations related to transport infrastructure.

    /**
     * @brief Allows the user to select a position for placing a road.
     *
     * Displays available positions on the city grid and lets the user choose one.
     * @param xPos Reference to the x-coordinate for the road's position.
     * @param yPos Reference to the y-coordinate for the road's position.
     */
    void chooseRoadPosition(int &xPos, int &yPos);

    /**
     * @brief Confirms the purchase of the road at the chosen position.
     *
     * Verifies resources, processes the purchase, and provides feedback to the user.
     * @param xPos The x-coordinate for the road's position.
     * @param yPos The y-coordinate for the road's position.
     */
    void confirmPurchase(int xPos, int yPos);
};

#endif // BUYROADMENU_H