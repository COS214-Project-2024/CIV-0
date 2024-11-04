/**
 * @file BuildingsStatMenu.h
 * @brief Declares the BuildingsStatMenu class for displaying statistics of various building types.
 */

#ifndef BUILDINGSSTATMENU_H
#define BUILDINGSSTATMENU_H

#include "menus/base/IMenu.h"
#include "utils/EntityType.h"
#include <vector>

/**
 * @class BuildingsStatMenu
 * @brief Provides a menu interface for displaying detailed statistics of various building types.
 *
 * The BuildingsStatMenu class allows players to view comprehensive statistics for selected building types,
 * including cost, utility consumption, and other attributes. The menu displays options to select a building
 * type and shows the associated statistics in a formatted layout.
 */
class BuildingsStatMenu : public IMenu
{
public:
    /**
     * @brief Constructs a BuildingsStatMenu object.
     *
     * Initializes the menu with a provided list of entity types for which statistics can be displayed.
     * @param types A vector containing the entity types to display statistics for.
     */
    BuildingsStatMenu(std::vector<EntityType> types);

    /**
     * @brief Destructor for BuildingsStatMenu.
     *
     * Cleans up any resources or memory used by the BuildingsStatMenu.
     */
    ~BuildingsStatMenu();

    /**
     * @brief Displays the entity type selection menu.
     *
     * Overrides the display method from IMenu to render the list of available building types
     * for which statistics can be viewed.
     */
    void display() const override;

    /**
     * @brief Handles user input to select a building type and display its statistics.
     *
     * Processes user input, allowing navigation between building types or returning to previous menus.
     */
    void handleInput() override;

private:
    std::vector<EntityType> entityTypes; ///< List of entity types for which statistics are available.

    /**
     * @brief Displays detailed statistics for a selected entity type.
     *
     * Shows comprehensive information for the chosen building type, including cost breakdown,
     * utility requirements, and additional attributes for different sizes (e.g., Small, Medium, Large).
     * @param type The entity type for which statistics are displayed.
     */
    void displayEntityStats(EntityType type) const;

    /**
     * @brief Displays a formatted row of statistics within a fixed-width box.
     *
     * Aligns the label and value dynamically to ensure a clean and organized display.
     * @param label The label for the statistic (e.g., "Cost").
     * @param value The value of the statistic (e.g., "1000").
     * @param boxWidth The width of the display box to maintain alignment.
     */
    void displayStatRow(const std::string &label, const std::string &value, int boxWidth) const;
};

#endif // BUILDINGSSTATMENU_H