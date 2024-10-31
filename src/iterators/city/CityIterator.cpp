#include "CityIterator.h"

/**
 * @brief Construct a new City Iterator with grid and iterateUnique set to true by default
 *
 * @param grid
 */
CityIterator::CityIterator(std::vector<std::vector<Entity *>> &grid)
    : Iterator(grid), iterateUnique(true)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

CityIterator::~CityIterator() {}

/**
 * @brief Construct a new City Iterator with option for iterateUnique
 *
 * @param grid
 * @param iterateUnique
 */
CityIterator::CityIterator(std::vector<std::vector<Entity *>> &grid, bool iterateUnique)
    : Iterator(grid), iterateUnique(iterateUnique)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited entity if iterateUnique is enabled
 *
 */
void CityIterator::first()
{
    visitedEntities.clear(); // Clear visited set if reusing the iterator
    row = 0;
    col = 0;

    // Iterate through the grid to find the first valid entity
    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            Entity *entity = grid[row][col];
            if ((!iterateUnique || !isVisited(entity)) && entity)
            {
                if (iterateUnique)
                    markVisited(entity);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no valid entity is found, set to end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited entity if iterateUnique is enabled
 *
 */
void CityIterator::next()
{
    if (currRow == grid.end())
        return;

    // Continue iterating from the current position to find the next entity
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            Entity *entity = grid[row][col];
            if ((!iterateUnique || !isVisited(entity)) && entity)
            {
                if (iterateUnique)
                    markVisited(entity);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set iterator to the end if no further entities are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another entity to iterate over
 *
 * @return true if there is another entity, false otherwise
 */
bool CityIterator::hasNext()
{
    if (currRow == grid.end())
        return false;

    // Save the current state
    auto tempRow = currRow;
    auto tempCurr = curr;
    int tempRowIdx = row;
    int tempColIdx = col;

    // Look ahead to find if there's another entity
    for (++tempColIdx; tempRowIdx < grid.size(); ++tempRowIdx, tempColIdx = 0)
    {
        for (; tempColIdx < grid[tempRowIdx].size(); ++tempColIdx)
        {
            Entity *entity = grid[tempRowIdx][tempColIdx];
            if ((!iterateUnique || !isVisited(entity)) && entity)
                return true;
        }
    }

    return false;
}

/**
 * @brief Returns the current entity
 *
 * @return Entity*
 */
Entity *CityIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
