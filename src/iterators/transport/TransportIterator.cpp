#include "TransportIterator.h"

/**
 * @brief Construct a new Transport Iterator:: Transport Iterator object
 */
TransportIterator::TransportIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Transport Iterator:: Transport Iterator object
 */
TransportIterator::~TransportIterator() {}

/**
 * @brief Construct a new Transport Iterator:: Transport Iterator object
 *
 * @param grid
 */
TransportIterator::TransportIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited Transport
 */
void TransportIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            Transport *transport = dynamic_cast<Transport *>(grid[row][col]);
            if (transport && !isVisited(transport))
            {
                markVisited(transport);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no transports are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited Transport
 */
void TransportIterator::next()
{
    if (currRow == grid.end())
        return;

    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            Transport *transport = dynamic_cast<Transport *>(grid[row][col]);
            if (transport && !isVisited(transport))
            {
                markVisited(transport);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further transports, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited Transport
 *
 * @return true if there is another unvisited Transport, false otherwise
 */
bool TransportIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current Transport
 *
 * @return Entity*
 */
Entity *TransportIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
