#include "EconomicBuildingIterator.h"
#include <iostream>

/**
 * @brief Construct a new Economic Building Iterator:: Economic Building Iterator object
 */
EconomicBuildingIterator::EconomicBuildingIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Economic Building Iterator:: Economic Building Iterator object
 */
EconomicBuildingIterator::~EconomicBuildingIterator() {}

/**
 * @brief Construct a new Economic Building Iterator:: Economic Building Iterator object
 *
 * @param grid
 */
EconomicBuildingIterator::EconomicBuildingIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited EconomicBuilding
 *
 */
void EconomicBuildingIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            EconomicBuilding *eBuilding = dynamic_cast<EconomicBuilding *>(grid[row][col]);
            if (eBuilding && !isVisited(eBuilding))
            {
                markVisited(eBuilding);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no economic buildings are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited EconomicBuilding
 *
 */
void EconomicBuildingIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next economic building in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            EconomicBuilding *eBuilding = dynamic_cast<EconomicBuilding *>(grid[row][col]);
            if (eBuilding && !isVisited(eBuilding))
            {
                markVisited(eBuilding);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further economic buildings, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited EconomicBuilding
 *
 * @return true if there is another unvisited EconomicBuilding, false otherwise
 */
bool EconomicBuildingIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current EconomicBuilding
 *
 * @return Entity*
 */
Entity *EconomicBuildingIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
