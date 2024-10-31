/**
 * @file CityManager.h
 * @brief Manages city operations, including initialization, updating entities, and managing building purchases and sales.
 */

#ifndef CITYMANAGER_H
#define CITYMANAGER_H

#include "entities/base/Entity.h"
#include <vector>
#include "city/City.h"

/**
 * @class CityManager
 * @brief Manages and maintains city entities and provides functions for updating city states.
 */
class CityManager
{
public:
    /**
     * @brief Constructs a CityManager instance.
     */
    CityManager();

    /**
     * @brief Destroys the CityManager instance.
     */
    ~CityManager();

    /**
     * @brief Initializes the city, creating required instances.
     */
    void initializeCity();

    /**
     * @brief Updates city attributes and entities for the next simulation loop.
     */
    void updateCity();

    /**
     * @brief Retrieves an entity at the specified coordinates.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @return Pointer to the entity at (x, y).
     */
    Entity *getEntity(int x, int y);

    /**
     * @brief Sells a building at the specified coordinates.
     * @param xPos X-coordinate of the building.
     * @param yPos Y-coordinate of the building.
     */
    void sellBuilding(int xPos, int yPos);

    /**
     * @brief Sells all buildings of a specified type.
     * @param type The type of entity to sell.
     */
    void sellAllBuildingsOfType(EntityType type);

    /**
     * @brief Gets available positions for placing a specified entity type.
     * @param type The type of entity.
     * @param size The size of the entity.
     * @return Vector of available positions as (x, y) coordinates.
     */
    std::vector<std::vector<int>> getAvailiablePositions(EntityType type, Size size);

    /**
     * @brief Checks if the city can afford to buy an entity of a specified type and size.
     * @param type The type of entity.
     * @param size The size of the entity.
     * @return True if affordable, false otherwise.
     */
    bool canAffordToBuy(EntityType type, Size size);

    /**
     * @brief Checks if an entity of a specified type and size can be placed at a specific position.
     * @param xPos X-coordinate.
     * @param yPos Y-coordinate.
     * @param type The type of entity.
     * @param size The size of the entity.
     * @return True if the entity can be placed, false otherwise.
     */
    bool canBuyAt(int xPos, int yPos, EntityType type, Size size);

    /**
     * @brief Attempts to purchase and place an entity of a specified type and size.
     * @param type The type of entity.
     * @param size The size of the entity.
     * @return True if the entity was successfully bought, false otherwise.
     */
    bool buyEntity(EntityType type, Size size);

    /**
     * @brief Generates a random city layout with roads and buildings.
     */
    void generateRandomCity();
};

#endif // CITYMANAGER_H
