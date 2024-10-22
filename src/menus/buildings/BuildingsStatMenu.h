#ifndef BUILDINGSSTATMENU_H
#define BUILDINGSSTATMENU_H

#include "menus/base/IMenu.h"
#include "utils/EntityType.h"
#include <vector>

/**
 * @brief Menu to display statistics of various buildings based on the entity types provided.
 * Allows the user to view detailed statistics of selected building types, including cost, utility requirements, and additional stats.
 */
class BuildingsStatMenu : public IMenu
{
public:
    /**
     * @brief Constructor for BuildingsStatMenu.
     * Initializes the menu with a list of entity types to display stats for.
     * @param types List of entity types to display stats for.
     */
    BuildingsStatMenu(std::vector<EntityType> types);

    /**
     * @brief Destructor for BuildingsStatMenu.
     */
    ~BuildingsStatMenu();

    /**
     * @brief Displays the building type selection menu.
     * Shows the list of available building types for which the stats can be viewed.
     */
    void display() const override;

    /**
     * @brief Handles user input to select a building type and display its stats.
     * Processes the user's selection and displays the relevant building stats.
     */
    void handleInput() override;

private:
    std::vector<EntityType> entityTypes; ///< List of entity types to display stats for.

    /**
     * @brief Displays the statistics for a selected entity type.
     * Presents detailed information such as cost, utility requirements, and additional stats.
     * @param type The entity type for which stats are displayed.
     */
    void displayEntityStats(EntityType type) const;

    /**
     * @brief Displays a formatted row of stats with dynamic padding.
     * Aligns the label and value in a visually pleasing manner within a fixed-width box.
     * @param label The stat label (e.g., "Cost").
     * @param value The stat value (e.g., "1000").
     * @param boxWidth The fixed width for the stats box.
     */
    void displayStatRow(const std::string &label, const std::string &value, int boxWidth) const;
};

#endif // BUILDINGSSTATMENU_H
