/**
 * @file DemolishMenu.h
 * @brief Declares the DemolishMenu class for handling building demolition within the game.
 */

#ifndef DEMOLISHMENU_H
#define DEMOLISHMENU_H

#include "menus/base/IMenu.h"
#include <vector>

/**
 * @class DemolishMenu
 * @brief Provides a menu interface for demolishing buildings in the game.
 *
 * The DemolishMenu class allows users to choose options for demolishing specific buildings
 * or all buildings of a particular type. It provides functionality for confirming and processing
 * the demolition of selected buildings.
 */
class DemolishMenu : public IMenu
{
public:
    /**
     * @brief Constructor for DemolishMenu.
     *
     * Initializes the menu with options for selecting buildings to demolish.
     */
    DemolishMenu();

    /**
     * @brief Destructor for DemolishMenu.
     */
    ~DemolishMenu();

    /**
     * @brief Displays the demolish menu.
     *
     * Clears the screen and shows the available demolition options.
     */
    void display() const override;

    /**
     * @brief Handles user input for the demolish menu.
     *
     * Processes user choices and navigates to specific demolition operations based on input.
     */
    void handleInput() override;

private:
    /**
     * @brief Presents a menu for demolishing a specific building.
     *
     * Lists individual buildings in the city and allows the user to choose one to demolish.
     */
    void demolishSpecificBuilding();

    /**
     * @brief Presents a menu for selecting and demolishing all buildings of a particular type.
     *
     * Allows the user to select a building type and demolishes all instances of that type in the city.
     */
    void demolishAllBuildingsOfType();

    /**
     * @brief Confirms the demolition of selected buildings.
     *
     * Displays a confirmation prompt and processes the demolition if confirmed.
     * @param positionsToDemolish A list of building positions to be demolished.
     */
    void confirmDemolish(const std::vector<std::pair<int, int>> &positionsToDemolish);
};

#endif // DEMOLISHMENU_H