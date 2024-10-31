#ifndef DEMOLISHMENU_H
#define DEMOLISHMENU_H

#include "menus/base/IMenu.h"
#include <vector>

/**
 * @brief Menu for demolishing buildings in the game.
 * Provides options to demolish a specific building or all buildings of a particular type.
 */
class DemolishMenu : public IMenu
{
public:
    /**
     * @brief Constructor for DemolishMenu.
     */
    DemolishMenu();

    /**
     * @brief Destructor for DemolishMenu.
     */
    ~DemolishMenu();

    /**
     * @brief Displays the demolish menu.
     */
    void display() const override;

    /**
     * @brief Handles user input for the demolish menu.
     */
    void handleInput() override;

private:
    /**
     * @brief Presents a menu for demolishing a specific building.
     */
    void demolishSpecificBuilding();

    /**
     * @brief Presents a menu for selecting and demolishing all buildings of a particular type.
     */
    void demolishAllBuildingsOfType();

    /**
     * @brief Helper function to confirm the demolition of buildings.
     * @param buildingsToDemolish A list of buildings the user is about to demolish.
     */
    void confirmDemolish(const std::vector<std::pair<int, int>> &positionsToDemolish);
};

#endif // DEMOLISHMENU_H
