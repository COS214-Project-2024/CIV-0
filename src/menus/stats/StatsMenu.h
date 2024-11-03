/**
 * @file StatsMenu.h
 * @brief Declares the StatsMenu class for managing and displaying city statistics and entity lists.
 */

#ifndef STATSMENU_H
#define STATSMENU_H

#include "menus/base/IMenu.h"
#include "city/City.h"

/**
 * @class StatsMenu
 * @brief Provides functionality for displaying city statistics and various entity listings.
 *
 * The StatsMenu class includes options to view general city statistics, list all city entities,
 * and display detailed information for specific types of buildings, utilities, and producers.
 */
class StatsMenu : public IMenu
{
public:
    /**
     * @brief Constructs a StatsMenu object.
     *
     * Initializes the StatsMenu with relevant headings and sections.
     */
    StatsMenu();

    /**
     * @brief Destructor for StatsMenu.
     *
     * Cleans up resources used by the StatsMenu.
     */
    ~StatsMenu();

    /**
     * @brief Displays the statistics menu.
     *
     * Overrides the display method of IMenu to show city statistics and available entity listings.
     */
    void display() const override;

    /**
     * @brief Handles user input in the statistics menu.
     *
     * Processes user selections for viewing various statistics and entity lists.
     */
    void handleInput() override;

private:
    void listEntities(Iterator *it, std::string (*labelGenerator)(Entity *), std::string heading);

    static std::string labelGenerator(Entity *entity);
    static std::string residentialLabelGenerator(Entity *entity);
    static std::string industrialLabelGenerator(Entity *entity);
    static std::string utilityLabelGenerator(Entity *entity);

    /**
     * @brief Displays overall city statistics including population, resources, and satisfaction.
     */
    void showCityStats();

    /**
     * @brief Formats the satisfaction percentage for display.
     *
     * @param satisfaction The satisfaction value to format.
     * @return A formatted string representation of the satisfaction value.
     */
    std::string formatSatisfaction(float satisfaction) const;
};

#endif // STATSMENU_H