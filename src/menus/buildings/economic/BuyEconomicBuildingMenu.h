#ifndef BUYECONOMICBUILDINGMENU_H
#define BUYECONOMICBUILDINGMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/BuildingManager.h"

/**
 * @brief Menu for purchasing economic buildings in the game.
 *
 * This class provides a user interface for selecting and buying different types of economic buildings,
 * such as Offices, Shopping Malls, and Factories. It extends the BuyMenu class to include specific logic
 * for handling economic buildings.
 */
class BuyEconomicBuildingMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyEconomicBuildingMenu.
     * Initializes the menu layout and configurations for economic building purchases.
     */
    BuyEconomicBuildingMenu();

    /**
     * @brief Destructor for BuyEconomicBuildingMenu.
     * Cleans up any resources or states related to the menu.
     */
    ~BuyEconomicBuildingMenu();

protected:
    /**
     * @brief Displays a list of economic building types for user selection.
     *
     * Overrides the pure virtual method from BuyMenu to present economic building options to the user.
     * This method handles displaying building types and capturing user input to select an option.
     *
     * @return The selected EntityType representing the chosen economic building.
     */
    EntityType chooseEntityType() override;

    /**
     * @brief Initiates the construction of the chosen economic building.
     *
     * This method handles the building process by interacting with the BuildingManager to create
     * an economic building at the specified location and size.
     *
     * @param type The type of economic building to construct (e.g., Office, Shopping Mall).
     * @param size The size category of the building (e.g., Small, Medium, Large).
     * @param xPos The x-coordinate for the building's placement.
     * @param yPos The y-coordinate for the building's placement.
     */
    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    BuildingManager buildingManager; ///< Manager responsible for handling building operations.
};

#endif // BUYECONOMICBUILDINGMENU_H
