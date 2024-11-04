#ifndef BUYUTILITYMENU_H
#define BUYUTILITYMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/UtilityManager.h"

/**
 * @brief Menu for purchasing utility buildings in the game.
 *
 * This class provides a user interface for selecting and purchasing various types of
 * utility buildings, such as Power Plants, Water Supplies, Waste Management facilities, and Sewage Systems.
 * It extends the BuyMenu class to handle utility-specific options and building logic.
 */
class BuyUtilityMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyUtilityMenu.
     * Initializes the menu layout and configurations for utility building purchases.
     */
    BuyUtilityMenu();

    /**
     * @brief Destructor for BuyUtilityMenu.
     * Cleans up any resources or states related to the utility menu.
     */
    ~BuyUtilityMenu();

protected:
    /**
     * @brief Displays a list of utility building types for user selection.
     *
     * Overrides the pure virtual method from BuyMenu to present specific utility-building options to the user.
     * This method displays utility options and processes user input to select an option.
     *
     * @return The selected EntityType representing the chosen utility building.
     */
    EntityType chooseEntityType() override;

    /**
     * @brief Initiates the construction of the selected utility building.
     *
     * This method interacts with the UtilityManager to create a building at the specified location and size.
     *
     * @param type The type of utility building to construct (e.g., Power Plant, Water Supply, etc.).
     * @param size The size category of the building (e.g., Small, Medium, Large).
     * @param xPos The x-coordinate for the building's placement.
     * @param yPos The y-coordinate for the building's placement.
     */
    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    UtilityManager utilityManager; ///< Manager responsible for handling utility-building operations.
};

#endif // BUYUTILITYMENU_H