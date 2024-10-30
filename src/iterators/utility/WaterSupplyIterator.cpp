#include "WaterSupplyIterator.h"

/**
 * @brief Construct a new Water Supply Iterator object
 */
WaterSupplyIterator::WaterSupplyIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Water Supply Iterator object
 */
WaterSupplyIterator::~WaterSupplyIterator() {}

/**
 * @brief Construct a new Water Supply Iterator object with grid
 *
 * @param grid
 */
WaterSupplyIterator::WaterSupplyIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Resets the iterator to the first unvisited WaterSupply
 */
void WaterSupplyIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            WaterSupply *ws = dynamic_cast<WaterSupply *>(grid[row][col]);
            if (ws && !isVisited(ws))
            {
                markVisited(ws);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no WaterSupply instances are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited WaterSupply
 */
void WaterSupplyIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next unvisited WaterSupply in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            WaterSupply *ws = dynamic_cast<WaterSupply *>(grid[row][col]);
            if (ws && !isVisited(ws))
            {
                markVisited(ws);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further WaterSupply instances, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited WaterSupply
 *
 * @return true if there is another unvisited WaterSupply, false otherwise
 */
bool WaterSupplyIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current WaterSupply
 *
 * @return Entity*
 */
Entity *WaterSupplyIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
