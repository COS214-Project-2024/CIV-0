#include "WasteManagementIterator.h"

/**
 * @brief Construct a new Waste Management Iterator object
 */
WasteManagementIterator::WasteManagementIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Waste Management Iterator object
 */
WasteManagementIterator::~WasteManagementIterator() {}

/**
 * @brief Construct a new Waste Management Iterator object with grid
 *
 * @param grid
 */
WasteManagementIterator::WasteManagementIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Resets the iterator to the first unvisited WasteManagement
 */
void WasteManagementIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            WasteManagement *wm = dynamic_cast<WasteManagement *>(grid[row][col]);
            if (wm && !isVisited(wm))
            {
                markVisited(wm);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no WasteManagement instances are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited WasteManagement
 */
void WasteManagementIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next unvisited WasteManagement in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            WasteManagement *wm = dynamic_cast<WasteManagement *>(grid[row][col]);
            if (wm && !isVisited(wm))
            {
                markVisited(wm);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further WasteManagement instances, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited WasteManagement
 *
 * @return true if there is another unvisited WasteManagement, false otherwise
 */
bool WasteManagementIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current WasteManagement
 *
 * @return Entity*
 */
Entity *WasteManagementIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
