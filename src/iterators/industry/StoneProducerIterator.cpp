#include "StoneProducerIterator.h"
#include <iostream>

/**
 * @brief Construct a new Stone Producer Iterator:: Stone Producer Iterator object
 */
StoneProducerIterator::StoneProducerIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Stone Producer Iterator:: Stone Producer Iterator object
 */
StoneProducerIterator::~StoneProducerIterator() {}

/**
 * @brief Construct a new Stone Producer Iterator:: Stone Producer Iterator object
 *
 * @param grid
 */
StoneProducerIterator::StoneProducerIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited StoneProducer
 *
 */
void StoneProducerIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            StoneProducer *producer = dynamic_cast<StoneProducer *>(grid[row][col]);
            if (producer && !isVisited(producer))
            {
                markVisited(producer);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no stone producers are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited StoneProducer
 *
 */
void StoneProducerIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next stone producer in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            StoneProducer *producer = dynamic_cast<StoneProducer *>(grid[row][col]);
            if (producer && !isVisited(producer))
            {
                markVisited(producer);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further stone producers, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited StoneProducer
 *
 * @return true if there is another unvisited StoneProducer, false otherwise
 */
bool StoneProducerIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current StoneProducer
 *
 * @return Entity*
 */
Entity *StoneProducerIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
