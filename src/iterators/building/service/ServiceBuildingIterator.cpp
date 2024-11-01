#include "ServiceBuildingIterator.h"
#include <iostream>

/**
 * @brief Construct a new Service Building Iterator:: Service Building Iterator object
 */
ServiceBuildingIterator::ServiceBuildingIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Service Building Iterator:: Service Building Iterator object
 */
ServiceBuildingIterator::~ServiceBuildingIterator() {}

/**
 * @brief Construct a new Service Building Iterator:: Service Building Iterator object
 *
 * @param grid
 */
ServiceBuildingIterator::ServiceBuildingIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited ServiceBuilding
 *
 */
void ServiceBuildingIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            ServiceBuilding *sBuilding = dynamic_cast<ServiceBuilding *>(grid[row][col]);
            if (sBuilding && !isVisited(sBuilding))
            {
                markVisited(sBuilding);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no service buildings are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited ServiceBuilding
 *
 */
void ServiceBuildingIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next service building in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            ServiceBuilding *sBuilding = dynamic_cast<ServiceBuilding *>(grid[row][col]);
            if (sBuilding && !isVisited(sBuilding))
            {
                markVisited(sBuilding);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further service buildings, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited ServiceBuilding
 *
 * @return true if there is another unvisited ServiceBuilding, false otherwise
 */
bool ServiceBuildingIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current ServiceBuilding
 *
 * @return Entity*
 */
Entity *ServiceBuildingIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
