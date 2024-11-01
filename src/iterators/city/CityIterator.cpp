#include "CityIterator.h"

/**
 * @brief Default constructor for CityIterator
 */
CityIterator::CityIterator() : Iterator(), unique(true)
{
    this->row = 0;
    this->col = 0;
}

CityIterator::~CityIterator() {}

/**
 * @brief Construct a new City Iterator:: City Iterator object with unique option
 *
 * @param grid
 * @param unique
 */
CityIterator::CityIterator(std::vector<std::vector<Entity *>> &grid, bool unique) : Iterator(grid), unique(unique)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Goes to the first Entity, respecting uniqueness if enabled
 */
void CityIterator::first()
{
    visitedEntities.clear(); // Clear visited set if reusing iterator
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            Entity *entity = grid[row][col];
            if (!unique || (unique && !isVisited(entity)))
            {
                if (unique)
                    markVisited(entity);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no entities are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next Entity, respecting uniqueness if enabled
 */
void CityIterator::next()
{
    if (currRow == grid.end())
        return;

    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            Entity *entity = grid[row][col];
            if (!unique || (unique && !isVisited(entity)))
            {
                if (unique)
                    markVisited(entity);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further entities, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited Entity
 *
 * @return true if there is another unvisited Entity, false otherwise
 */
bool CityIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current Entity
 *
 * @return Entity*
 */
Entity *CityIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
