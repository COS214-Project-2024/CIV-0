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
     * @brief Lists all entities present in the city.
     */
    void listAllCityEntities();

    /**
     * @brief Lists all building entities in the city.
     */
    void listAllBuildings();

    /**
     * @brief Lists all utility entities in the city.
     */
    void listAllUtilities();

    /**
     * @brief Lists all road entities in the city.
     */
    void listAllRoads();

    /**
     * @brief Lists all transport-related entities in the city.
     */
    void listAllTransport();

    /**
     * @brief Lists all economic buildings in the city.
     */
    void listAllEconomicBuildings();

    /**
     * @brief Lists all residential buildings in the city.
     */
    void listAllResidentialBuildings();

    /**
     * @brief Lists all service buildings in the city.
     */
    void listAllServiceBuildings();

    /**
     * @brief Lists all amenities in the city.
     */
    void listAllAmenities();

    /**
     * @brief Lists all power plants in the city.
     */
    void listAllPowerPlants();

    /**
     * @brief Lists all water supply entities in the city.
     */
    void listAllWaterSupplies();

    /**
     * @brief Lists all waste management facilities in the city.
     */
    void listAllWasteManagement();

    /**
     * @brief Lists all sewage systems in the city.
     */
    void listAllSewageSystems();

    /**
     * @brief Lists all concrete-producing entities in the city.
     */
    void listAllConcreteProducers();

    /**
     * @brief Lists all stone-producing entities in the city.
     */
    void listAllStoneProducers();

    /**
     * @brief Lists all wood-producing entities in the city.
     */
    void listAllWoodProducers();

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