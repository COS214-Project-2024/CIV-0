#ifndef BUYROADMENU_H
#define BUYROADMENU_H

#include "menus/base/IMenu.h"
#include "managers/TransportManager.h"

/**
 * @brief Represents a menu for buying roads in the game.
 * Allows the user to choose a position to place a road and confirms the purchase.
 */
class BuyRoadMenu : public IMenu
{
public:
    /**
     * @brief Constructs a new BuyRoadMenu object.
     */
    BuyRoadMenu();

    /**
     * @brief Destructor for BuyRoadMenu.
     */
    virtual ~BuyRoadMenu();

    /**
     * @brief Displays the road buying menu.
     */
    void display() const override;

    /**
     * @brief Handles input for selecting a position and confirming the road purchase.
     */
    void handleInput() override;

private:
    TransportManager transportManager;

    /**
     * @brief Allows the user to select a position for the road.
     * @param xPos Reference to the x-coordinate for the road's position.
     * @param yPos Reference to the y-coordinate for the road's position.
     */
    void chooseRoadPosition(int &xPos, int &yPos);

    /**
     * @brief Confirms the purchase of the road at the selected position.
     * @param xPos The x-coordinate for the road's position.
     * @param yPos The y-coordinate for the road's position.
     */
    void confirmPurchase(int xPos, int yPos);
};

#endif // BUYROADMENU_H
