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
    /**
     * @brief Lists the entities based on the provided iterator and label generator.
     *
     * @param it The iterator for city entities.
     * @param labelGenerator The function to generate labels for entities.
     * @param heading The heading for the entity list.
     */
    void listEntities(Iterator *it, std::string (*labelGenerator)(Entity *), std::string heading);

    /**
     * @brief Generates a label for a general entity.
     *
     * @param entity The entity to label.
     * @return The generated label string.
     */
    static std::string labelGenerator(Entity *entity);

    /**
     * @brief Generates a label for a residential building entity.
     *
     * @param entity The residential building entity to label.
     * @return The generated label string with satisfaction.
     */
    static std::string residentialLabelGenerator(Entity *entity);

    /**
     * @brief Generates a label for an industrial entity.
     *
     * @param entity The industrial entity to label.
     * @return The generated label string with production rate and level.
     */
    static std::string industrialLabelGenerator(Entity *entity);

    /**
     * @brief Generates a label for a utility entity.
     *
     * @param entity The utility entity to label.
     * @return The generated label string with level information.
     */
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