#include "RoadIterator.h"

/**
 * @brief Construct a new Road Iterator:: Road Iterator object
 */
RoadIterator::RoadIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Road Iterator:: Road Iterator object
 */
RoadIterator::~RoadIterator() {}

/**
 * @brief Construct a new Road Iterator:: Road Iterator object
 *
 * @param grid
 */
RoadIterator::RoadIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited Road
 */
void RoadIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            Road *road = dynamic_cast<Road *>(grid[row][col]);
            if (road && !isVisited(road))
            {
                markVisited(road);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no roads are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited Road
 */
void RoadIterator::next()
{
    if (currRow == grid.end())
        return;

    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            Road *road = dynamic_cast<Road *>(grid[row][col]);
            if (road && !isVisited(road))
            {
                markVisited(road);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further roads, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited Road
 *
 * @return true if there is another unvisited Road, false otherwise
 */
bool RoadIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current Road
 *
 * @return Entity*
 */
Entity *RoadIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
