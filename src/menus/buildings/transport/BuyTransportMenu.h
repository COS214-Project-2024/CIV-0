#ifndef BUYTRANSPORTMENU_H
#define BUYTRANSPORTMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/TransportManager.h"

/**
 * @brief Menu for purchasing transport buildings in the game.
 *
 * This class provides a user interface for selecting and purchasing various types of
 * transport buildings, such as Bus Stops, Airports, and Train Stations. It extends the
 * BuyMenu class to handle transport-specific options and building logic.
 */
class BuyTransportMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyTransportMenu.
     * Initializes the menu layout and configurations for transport building purchases.
     */
    BuyTransportMenu();

    /**
     * @brief Destructor for BuyTransportMenu.
     * Cleans up any resources or states related to the transport menu.
     */
    ~BuyTransportMenu();

protected:
    /**
     * @brief Displays a list of transport building types for user selection.
     *
     * Overrides the pure virtual method from BuyMenu to present specific transport-building options to the user.
     * This method displays transport options and processes user input to select an option.
     *
     * @return The selected EntityType representing the chosen transport building.
     */
    EntityType chooseEntityType() override;

    /**
     * @brief Initiates the construction of the selected transport building.
     *
     * This method interacts with the TransportManager to create a building at the specified location and size.
     *
     * @param type The type of transport building to construct (e.g., Bus Stop, Airport, Train Station).
     * @param size The size category of the building (e.g., Small, Medium, Large).
     * @param xPos The x-coordinate for the building's placement.
     * @param yPos The y-coordinate for the building's placement.
     */
    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    TransportManager transportManager; ///< Manager responsible for handling transport-building operations.
};

#endif // BUYTRANSPORTMENU_H
