#include "IndustryIterator.h"

/**
 * @brief Construct a new Industry Iterator:: Industry Iterator object
 */
IndustryIterator::IndustryIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Industry Iterator:: Industry Iterator object
 */
IndustryIterator::~IndustryIterator() {}

/**
 * @brief Construct a new Industry Iterator:: Industry Iterator object
 *
 * @param grid
 */
IndustryIterator::IndustryIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited Industry
 */
void IndustryIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            Industry *industry = dynamic_cast<Industry *>(grid[row][col]);
            if (industry && !isVisited(industry))
            {
                markVisited(industry);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no industry entities are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited Industry
 */
void IndustryIterator::next()
{
    if (currRow == grid.end())
        return;

    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            Industry *industry = dynamic_cast<Industry *>(grid[row][col]);
            if (industry && !isVisited(industry))
            {
                markVisited(industry);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further industry entities, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited Industry
 *
 * @return true if there is another unvisited Industry, false otherwise
 */
bool IndustryIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current Industry
 *
 * @return Entity*
 */
Entity *IndustryIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
