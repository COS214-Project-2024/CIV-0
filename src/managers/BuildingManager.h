/**
 * @file BuildingManager.h
 * @brief Header file for the BuildingManager class.
 */

#ifndef BUILDINGMANAGER_H
#define BUILDINGMANAGER_H

#include <string>
#include "utils/ConfigManager.h"

/**
 * @class BuildingManager
 * @brief Manages the construction of residential buildings in the city.
 */
class BuildingManager
{
public:
    /**
     * @brief Constructs a new BuildingManager object.
     */
    BuildingManager();

    /**
     * @brief Destroys the BuildingManager object.
     */
    ~BuildingManager();

    /**
     * @brief Builds a residential building of specified type and size at given coordinates.
     * 
     * @param type The type of the residential building to build.
     * @param size The size of the building (SMALL, MEDIUM, LARGE).
     * @param x The x-coordinate where the building should be placed.
     * @param y The y-coordinate where the building should be placed.
     * @return true if the building was successfully created and added to the city.
     * @return false if building creation failed.
     */
    bool buildBuilding(EntityType type, Size size, int x, int y);
};

#endif // BUILDINGMANAGER_H
