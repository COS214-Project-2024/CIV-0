#include "City.h"

City::City() : satisfaction(0), money(0), wood(0), steel(0), concrete(0),
               populationCapacity(0), population(0), electricityProduction(0),
               electricityConsumption(0), waterProduction(0), waterConsumption(0),
               residentialTax(0), economicTax(0)
{
    // You can initialize the grid and other members here as needed
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
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size())
    {
        return grid[x][y];
    }
    return nullptr; // Return nullptr if coordinates are out of bounds
}
