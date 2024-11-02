/**
 * @file DisplayCityMenu.h
 * @brief Declares the DisplayCityMenu class for showing various city views in the game.
 */

#ifndef DISPLAYCITYMENU_H
#define DISPLAYCITYMENU_H

#include "menus/base/IMenu.h"

/**
 * @class DisplayCityMenu
 * @brief Provides functionality to display the city and filter views by entity type.
 *
 * The DisplayCityMenu class allows players to view the entire city or filter the view to show
 * specific types of entities such as residential buildings, economic buildings, services, utilities,
 * industries, and transport systems.
 */
class DisplayCityMenu : public IMenu
{
public:
    /**
     * @brief Constructs the DisplayCityMenu.
     *
     * Initializes the menu with various display options and navigation.
     */
    DisplayCityMenu();

    /**
     * @brief Destructor for DisplayCityMenu.
     *
     * Cleans up any resources used by the DisplayCityMenu.
     */
    ~DisplayCityMenu();

    /**
     * @brief Displays the "Display City" menu and the current city view.
     *
     * This method overrides the display method of IMenu to render the menu and show the city grid based on
     * the selected display mode.
     */
    void display() const override;

    /**
     * @brief Handles user input for the "Display City" menu.
     *
     * Allows the player to choose display modes or navigate back to the main menu.
     * Processes the user’s selection and updates the current display mode accordingly.
     */
    void handleInput() override;

private:
    /**
     * @enum DisplayMode
     * @brief Represents the different modes available for displaying the city.
     */
    enum class DisplayMode
    {
        WHOLE_CITY,  ///< Display the entire city grid.
        RESIDENTIAL, ///< Display only residential buildings.
        ECONOMIC,    ///< Display only economic buildings.
        SERVICE,     ///< Display only service buildings.
        UTILITY,     ///< Display only utility buildings.
        INDUSTRY,    ///< Display only industrial entities.
        TRANSPORT    ///< Display only transport-related entities.
    };

    DisplayMode currentDisplayMode = DisplayMode::WHOLE_CITY; ///< The current mode for displaying the city.

    /**
     * @brief Displays the entire city grid without any filtering.
     *
     * Renders the grid layout showing all types of entities present in the city.
     */
    void displayCity() const;

    /**
     * @brief Displays the city grid filtered by a specific type of entity.
     *
     * @tparam T The type of entity to display (e.g., ResidentialBuilding).
     * Renders the grid showing only entities of the specified type.
     */
    template <typename T>
    void displayCityByType() const;

    /**
     * @brief Determines which display function to call based on the current display mode.
     *
     * Calls the appropriate display function to show the city or filtered entities.
     */
    void displayFilteredCity() const;
};

#endif // DISPLAYCITYMENU_H