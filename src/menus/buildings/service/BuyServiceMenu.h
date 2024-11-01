#ifndef BUYSERVICEMENU_H
#define BUYSERVICEMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/ServiceManager.h"

/**
 * @brief Menu for purchasing service buildings in the game.
 *
 * This class provides a user interface for selecting and purchasing different types of
 * service buildings, such as Police Stations, Schools, and Hospitals. It extends the BuyMenu
 * class to include specific logic for handling service-related structures.
 */
class BuyServiceMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyServiceMenu.
     * Initializes the menu layout and configurations for service building purchases.
     */
    BuyServiceMenu();

    /**
     * @brief Destructor for BuyServiceMenu.
     * Cleans up any resources or states related to the menu.
     */
    ~BuyServiceMenu();

protected:
    /**
     * @brief Displays a list of service building types for user selection.
     *
     * Overrides the pure virtual method from BuyMenu to present specific service-building options to the user.
     * This method displays building types and handles user input to select an option.
     *
     * @return The selected EntityType representing the chosen service building.
     */
    EntityType chooseEntityType() override;

    /**
     * @brief Initiates the construction of the selected service building.
     *
     * This method interacts with the ServiceManager to create a building at the specified location and size.
     *
     * @param type The type of service building to construct (e.g., Police Station, School, Hospital).
     * @param size The size category of the building (e.g., Small, Medium, Large).
     * @param xPos The x-coordinate for the building's placement.
     * @param yPos The y-coordinate for the building's placement.
     */
    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    ServiceManager serviceManager; ///< Manager responsible for handling service-building operations.
};

#endif // BUYSERVICEMENU_H
