#include "UtilityIterator.h"

/**
 * @brief Construct a new Utility Iterator object
 */
UtilityIterator::UtilityIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Utility Iterator object
 */
UtilityIterator::~UtilityIterator() {}

/**
 * @brief Construct a new Utility Iterator object with grid
 *
 * @param grid
 */
UtilityIterator::UtilityIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Resets the iterator to the first unvisited Utility instance
 */
void UtilityIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            Utility *util = dynamic_cast<Utility *>(grid[row][col]);
            if (util && !isVisited(util))
            {
                markVisited(util);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no Utility instances are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited Utility instance
 */
void UtilityIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next unvisited Utility in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            Utility *util = dynamic_cast<Utility *>(grid[row][col]);
            if (util && !isVisited(util))
            {
                markVisited(util);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further Utility instances, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited Utility instance
 *
 * @return true if there is another unvisited Utility, false otherwise
 */
bool UtilityIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current Utility instance pointed to by the iterator
 *
 * @return A pointer to the current Utility instance
 */
Entity *UtilityIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
