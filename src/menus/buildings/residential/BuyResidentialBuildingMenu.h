#ifndef BUYRESIDENTIALBUILDINGMENU_H
#define BUYRESIDENTIALBUILDINGMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/BuildingManager.h"

/**
 * @brief Menu for purchasing residential buildings in the game.
 *
 * This class provides a user interface for selecting and buying different types of residential buildings,
 * such as Houses and Apartments. It extends the BuyMenu class to include specific logic
 * for handling residential buildings.
 */
class BuyResidentialBuildingMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyResidentialBuildingMenu.
     * Initializes the menu layout and configurations for residential building purchases.
     */
    BuyResidentialBuildingMenu();

    /**
     * @brief Destructor for BuyResidentialBuildingMenu.
     * Cleans up any resources or states related to the menu.
     */
    ~BuyResidentialBuildingMenu();

protected:
    /**
     * @brief Displays a list of residential building types for user selection.
     *
     * Overrides the pure virtual method from BuyMenu to present residential building options to the user.
     * This method handles displaying building types and capturing user input to select an option.
     *
     * @return The selected EntityType representing the chosen residential building.
     */
    EntityType chooseEntityType() override;

    /**
     * @brief Initiates the construction of the chosen residential building.
     *
     * This method handles the building process by interacting with the BuildingManager to create
     * a residential building at the specified location and size.
     *
     * @param type The type of residential building to construct (e.g., House, Apartment).
     * @param size The size category of the building (e.g., Small, Medium, Large).
     * @param xPos The x-coordinate for the building's placement.
     * @param yPos The y-coordinate for the building's placement.
     */
    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    BuildingManager buildingManager; ///< Manager responsible for handling building operations.
};

#endif // BUYRESIDENTIALBUILDINGMENU_H