#include "SewageSystemIterator.h"

/**
 * @brief Construct a new Sewage System Iterator object
 */
SewageSystemIterator::SewageSystemIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Sewage System Iterator object
 */
SewageSystemIterator::~SewageSystemIterator() {}

/**
 * @brief Construct a new Sewage System Iterator object with grid
 *
 * @param grid
 */
SewageSystemIterator::SewageSystemIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Resets the iterator to the first unvisited SewageSystem
 */
void SewageSystemIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            SewageSystem *system = dynamic_cast<SewageSystem *>(grid[row][col]);
            if (system && !isVisited(system))
            {
                markVisited(system);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no SewageSystem instances are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited SewageSystem
 */
void SewageSystemIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next unvisited SewageSystem in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            SewageSystem *system = dynamic_cast<SewageSystem *>(grid[row][col]);
            if (system && !isVisited(system))
            {
                markVisited(system);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further SewageSystems, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited SewageSystem
 *
 * @return true if there is another unvisited SewageSystem, false otherwise
 */
bool SewageSystemIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current SewageSystem
 *
 * @return Entity*
 */
Entity *SewageSystemIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
