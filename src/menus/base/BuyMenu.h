#ifndef BUYMENU_H
#define BUYMENU_H

#include "menus/base/IMenu.h"
#include "utils/EntityType.h"
#include "utils/Size.h"

/**
 * @brief Abstract class representing the Buy Menu in the game.
 * It handles the logic for purchasing buildings of various types and sizes.
 */
class BuyMenu : public IMenu
{
public:
    /**
     * @brief Default constructor for BuyMenu.
     * Initializes available resources for purchase.
     */
    BuyMenu();

    /**
     * @brief Destructor for BuyMenu.
     */
    virtual ~BuyMenu();

    /**
     * @brief Displays the base buy menu.
     * This function is overridden by derived classes.
     */
    void display() const override;

    /**
     * @brief Handles user input in the base buy menu.
     * This function manages the purchase workflow.
     */
    void handleInput() override;

protected:
    /**
     * @brief Converts x and y coordinates to a labeled string (e.g., "A, 1").
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return A formatted string representing the labeled coordinates.
     */
    std::string coordinatesToLabel(int x, int y) const;

    /**
     * @brief Displays available positions for the building on the city grid.
     * Positions are marked based on availability for the given building type and size.
     * @param positions Vector of available positions.
     * @param width Width of the city grid.
     * @param height Height of the city grid.
     */
    void displayAvailablePositions(const std::vector<std::vector<int>> &positions) const;

    /**
     * @brief Pure virtual function to choose the entity type.
     * Must be implemented by derived classes to allow dynamic selection of entity types.
     * @return EntityType The type of the entity chosen.
     */
    virtual EntityType chooseEntityType() = 0;

    /**
     * @brief Allows the user to select the size of the building to be purchased.
     * Ensures affordability based on available resources.
     * @param type The EntityType of the building.
     * @return Size The selected size of the building.
     */
    Size chooseBuildingSize(EntityType type);

    /**
     * @brief Allows the user to choose the position of the building to be placed.
     * @param xPos Reference to the x-coordinate for the building's position.
     * @param yPos Reference to the y-coordinate for the building's position.
     */
    void chooseBuildingPosition(int &xPos, int &yPos, EntityType type, Size size);

    /**
     * @brief Confirms the purchase of the selected building.
     * Displays a summary of the purchase including costs and position.
     * @param type The type of the building.
     * @param size The size of the building.
     * @param xPos The x-coordinate for the building's position.
     * @param yPos The y-coordinate for the building's position.
     */
    void confirmPurchase(EntityType type, Size size, int xPos, int yPos);

    virtual void buildEntity(EntityType type, Size size, int xPos, int yPos) = 0;

    int availableMoney;    ///< Available money for purchasing buildings.
    int availableWood;     ///< Available wood for purchasing buildings.
    int availableStone;    ///< Available stone for purchasing buildings.
    int availableConcrete; ///< Available concrete for purchasing buildings.
};

#endif // BUYMENU_H
