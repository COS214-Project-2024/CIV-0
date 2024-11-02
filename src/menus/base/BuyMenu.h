/**
 * @file BuyMenu.h
 * @brief Defines the BuyMenu class, an abstract menu for handling building purchases.
 */

#ifndef BUYMENU_H
#define BUYMENU_H

#include "menus/base/IMenu.h"
#include "utils/EntityType.h"
#include "utils/Size.h"

/**
 * @class BuyMenu
 * @brief Abstract class representing the Buy Menu in the game.
 *
 * This class provides the interface and common functionality for menus that handle the purchase
 * of buildings of different types and sizes. Derived classes must implement type-specific logic.
 */
class BuyMenu : public IMenu
{
public:
    /**
     * @brief Constructs a new BuyMenu object with default initialization.
     *
     * This constructor initializes the BuyMenu, setting up the necessary resources for display.
     */
    BuyMenu();

    /**
     * @brief Destructor for the BuyMenu class.
     *
     * Ensures proper cleanup of resources used by the menu.
     */
    virtual ~BuyMenu();

    /**
     * @brief Displays the base buy menu.
     *
     * This method should be overridden by derived classes to implement specific display logic.
     */
    void display() const override;

    /**
     * @brief Handles user input for the buy menu.
     *
     * This method manages the workflow for purchasing a building, including type, size, and position selection,
     * and final confirmation of the purchase.
     */
    void handleInput() override;

protected:
    EntityType selectedType; ///< The currently selected type of the entity for purchase.
    Size selectedSize;       ///< The currently selected size of the entity for purchase.

    /**
     * @brief Selects the type of entity to be purchased.
     *
     * This pure virtual function must be implemented by derived classes to allow dynamic selection of entity types.
     * @return EntityType The chosen type of entity.
     */
    virtual EntityType chooseEntityType() = 0;

    /**
     * @brief Allows the user to select the size of the building to be purchased.
     *
     * Ensures that the selected size is affordable based on the city's available resources. Displays an error message
     * if the selected size cannot be afforded.
     * @param type The type of the entity being purchased.
     * @return Size The chosen size of the building.
     */
    Size chooseBuildingSize(EntityType type);

    /**
     * @brief Allows the user to choose the position of the building on the city grid.
     *
     * Displays a grid with available positions based on the type and size of the entity, and prompts the user to select
     * a valid position.
     * @param xPos Reference to the x-coordinate for the chosen position.
     * @param yPos Reference to the y-coordinate for the chosen position.
     * @param type The type of the building being placed.
     * @param size The size of the building being placed.
     */
    void chooseBuildingPosition(int &xPos, int &yPos, EntityType type, Size size);

    /**
     * @brief Confirms the purchase of the selected building.
     *
     * Displays a summary of the purchase details, including type, size, and cost. Asks for final confirmation
     * from the user before proceeding with the purchase.
     * @param type The type of the building being purchased.
     * @param size The size of the building being purchased.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     */
    void confirmPurchase(EntityType type, Size size, int xPos, int yPos);

    /**
     * @brief Pure virtual method to handle the building of the entity.
     *
     * This method must be implemented by derived classes to specify the logic for constructing the selected entity
     * on the city grid.
     * @param type The type of entity to build.
     * @param size The size of the entity.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     */
    virtual void buildEntity(EntityType type, Size size, int xPos, int yPos) = 0;

    /**
     * @brief Displays available positions on the city grid with visualization of the entity's size.
     *
     * Highlights potential positions for placement and ensures proper boundary handling for larger entities.
     * @param positions A vector of available grid positions.
     */
    void displayAvailablePositions(const std::vector<std::vector<int>> &positions) const override;
};

#endif // BUYMENU_H
