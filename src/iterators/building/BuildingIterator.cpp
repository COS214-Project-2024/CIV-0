#include "BuildingIterator.h"
#include <iostream>

/**
 * @brief Construct a new Building Iterator:: Building Iterator object
 */
BuildingIterator::BuildingIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Building Iterator:: Building Iterator object
 */
BuildingIterator::~BuildingIterator() {}

/**
 * @brief Construct a new Building Iterator:: Building Iterator object
 *
 * @param grid
 */
BuildingIterator::BuildingIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited Building
 */
void BuildingIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            Building *building = dynamic_cast<Building *>(grid[row][col]);
            if (building && !isVisited(building))
            {
                markVisited(building);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no buildings are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited Building
 */
void BuildingIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next building in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            Building *building = dynamic_cast<Building *>(grid[row][col]);
            if (building && !isVisited(building))
            {
                markVisited(building);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further buildings, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited Building
 *
 * @return true if there is another unvisited Building, false otherwise
 */
bool BuildingIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current Building
 *
 * @return Entity*
 */
Entity *BuildingIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
