#include "City.h"
#include "entities/base/Entity.h"

City::City() : width(10), height(10), // Set default values
               satisfaction(0), money(0), wood(0), steel(0), concrete(0),
               populationCapacity(0), population(0), electricityProduction(0),
               electricityConsumption(0), waterProduction(0), waterConsumption(0),
               residentialTax(0), economicTax(0)
{
    // Initialize grid with default width and height
    grid.resize(height, std::vector<Entity *>(width, nullptr));
}

City::~City() {}

/**
 * @brief Returns a pointer to the singleton instance of City.
 * @return A pointer to the City instance.
 */
City *City::instance()
{
    // Correct singleton pattern implementation with a static object
    static City instance; // Static instance of City
    return &instance;     // Return the address of the static instance
}

Entity *City::getEntity(int x, int y)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        return grid[x][y];
    }
    return nullptr; // Return nullptr if coordinates are out of bounds
}

int City::getWidth()
{
    return width;
}

int City::getHeight()
{
    return height;
}
