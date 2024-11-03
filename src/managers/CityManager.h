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
     * @brief Generates a random city with an optional seed for reproducibility.
     * 
     * This function creates a new city layout based on a random generation algorithm. 
     * The seed can be specified to produce consistent results for testing.
     * This function is used for testing and demonstration purposes.
     * 
     * @param seed An optional seed value for the random number generator. If not provided, a random seed is used.
     */
    void generateCity(std::optional<unsigned int> seed = std::nullopt);

    /**
     * @brief Generates random roads within the specified grid dimensions.
     * 
     * This function creates random roads on the city grid, ensuring they fit within 
     * the specified dimensions and have a minimum width and height.
     * 
     * @param gridWidth The width of the grid in which to generate roads.
     * @param gridHeight The height of the grid in which to generate roads.
     * @param minWidth The minimum width of each road segment.
     * @param minHeight The minimum height of each road segment.
     * @param roadGap The gap between consecutive road segments to avoid overlaps.
     */
    void generateRandomRoads(int gridWidth, int gridHeight, int minWidth, int minHeight, int roadGap);

    /**
     * @brief Generates random buildings based on a specified placement probability.
     * 
     * This function places buildings randomly across the city grid, with the likelihood 
     * of placement determined by the provided probability value.
     * 
     * @param placementProbability The probability of placing a building in each grid cell.
     */
    void generateRandomBuildings(int placementProbability);
};

#endif // CITYMANAGER_H
