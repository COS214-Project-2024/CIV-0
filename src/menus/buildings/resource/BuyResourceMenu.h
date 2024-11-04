#ifndef BUYRESOURCEMENU_H
#define BUYRESOURCEMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/ResourceManager.h"

/**
 * @brief Menu for purchasing resource-producing buildings in the game.
 *
 * This class provides a user interface for selecting and purchasing different types of
 * resource-producing buildings, such as Wood Production facilities, Stone Quarries, and Concrete Factories.
 * It extends the BuyMenu class to include specific logic for handling resource-based structures.
 */
class BuyResourceMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyResourceMenu.
     * Initializes the menu layout and configurations for resource-producing building purchases.
     */
    BuyResourceMenu();

    /**
     * @brief Destructor for BuyResourceMenu.
     * Cleans up any resources or states related to the menu.
     */
    ~BuyResourceMenu();

protected:
    /**
     * @brief Displays a list of resource-producing building types for user selection.
     *
     * Overrides the pure virtual method from BuyMenu to present specific resource-building options to the user.
     * This method displays building types and handles user input to select an option.
     *
     * @return The selected EntityType representing the chosen resource-producing building.
     */
    EntityType chooseEntityType() override;

    /**
     * @brief Initiates the construction of the selected resource-producing building.
     *
     * This method interacts with the ResourceManager to create a building at the specified location and size.
     *
     * @param type The type of resource-producing building to construct (e.g., Wood Production, Stone Quarry).
     * @param size The size category of the building (e.g., Small, Medium, Large).
     * @param xPos The x-coordinate for the building's placement.
     * @param yPos The y-coordinate for the building's placement.
     */
    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    ResourceManager resourceManager; ///< Manager responsible for handling resource-building operations.
};

#endif // BUYRESOURCEMENU_H