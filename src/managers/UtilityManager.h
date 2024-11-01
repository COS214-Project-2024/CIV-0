/**
 * @file UtilityManager.h
 * @brief Manages utility creation, upgrades, and statistics within the city.
 */

#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H

#include "utils/EntityType.h"
#include "utils/Size.h"
#include "entities/utility/base/Utility.h"
#include "city/City.h"
#include "factory/utility/UtilityFactory.h"
#include "iterators/utility/UtilityIterator.h"
#include "iterators/utility/WaterSupplyIterator.h"
#include "iterators/utility/PowerPlantIterator.h"
#include "iterators/utility/WasteManagementIterator.h"
#include "iterators/utility/SewageSystemIterator.h"
#include <vector>

/**
 * @class UtilityManager
 * @brief Responsible for creating and managing utilities within the city, 
 * handling utility upgrades, and gathering utility-related statistics.
 */
class UtilityManager
{
public:
    /**
     * @brief Constructs a new UtilityManager instance.
     */
    UtilityManager();

    /**
     * @brief Destroys the UtilityManager instance, freeing resources.
     */
    ~UtilityManager();

    /**
     * @brief Builds a utility of the specified type, size, and location within the city.
     * @param type Type of utility to build (e.g., PowerPlant, WaterSupply).
     * @param size Size of the utility (e.g., small, medium, large).
     * @param x X-coordinate in the city grid.
     * @param y Y-coordinate in the city grid.
     */
    bool buildUtility(EntityType type, Size size, int x, int y);

    /**
     * @brief Gets the total electricity production across all utilities in the city.
     * @return Total electricity production.
     */
    int getElectricityProduction();

    /**
     * @brief Gets the total electricity consumption across all utilities in the city.
     * @return Total electricity consumption.
     */
    int getElectricityConsumption();

    /**
     * @brief Gets the total water production across all utilities in the city.
     * @return Total water production.
     */
    int getWaterProduction();

    /**
     * @brief Gets the total water consumption across all utilities in the city.
     * @return Total water consumption.
     */
    int getWaterConsumption();

    /**
     * @brief Gets the total waste production across all utilities in the city.
     * @return Total waste production.
     */
    int getWasteProduction();

    /**
     * @brief Gets the total waste consumption across all utilities in the city.
     * @return Total waste consumption.
     */
    int getWasteConsumption();

    /**
     * @brief Gets the total sewage production across all utilities in the city.
     * @return Total sewage production.
     */
    int getSewageProduction();

    /**
     * @brief Gets the total sewage consumption across all utilities in the city.
     * @return Total sewage consumption.
     */
    int getSewageConsumption();

    /**
     * @brief Retrieves a list of all utility entities within the city.
     * @return Vector of pointers to Utility objects.
     */
    std::vector<Utility*> getAllUtilities();

    /**
     * @brief Retrieves a list of all water supply utilities within the city.
     * @return Vector of pointers to WaterSupply Utility objects.
     */
    std::vector<Utility*> getAllWaterSupplies();

    /**
     * @brief Retrieves a list of all power plant utilities within the city.
     * @return Vector of pointers to PowerPlant Utility objects.
     */
    std::vector<Utility*> getAllPowerPlants();

    /**
     * @brief Retrieves a list of all waste management utilities within the city.
     * @return Vector of pointers to WasteManagement Utility objects.
     */
    std::vector<Utility*> getAllWasteManagements();

    /**
     * @brief Retrieves a list of all sewage system utilities within the city.
     * @return Vector of pointers to SewageSystem Utility objects.
     */
    std::vector<Utility*> getAllSewageSystems();

    /**
     * @brief Checks if the city has sufficient resources to afford an upgrade for a specified utility.
     * @param utility Pointer to the utility to check.
     * @return True if the upgrade is affordable, false otherwise.
     */
    bool canAffordUpgrade(Utility* utility);

    /**
     * @brief Upgrades a specified utility, if possible.
     * @param utility Reference to the pointer of the utility to be upgraded.
     * @return True if the upgrade was successful, false otherwise.
     */
    bool upgrade(Utility*& utility);
};

#endif // UTILITYMANAGER_H