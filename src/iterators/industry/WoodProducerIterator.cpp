#include "WoodProducerIterator.h"

/**
 * @brief Construct a new Wood Producer Iterator:: Wood Producer Iterator object
 */
WoodProducerIterator::WoodProducerIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Wood Producer Iterator:: Wood Producer Iterator object
 */
WoodProducerIterator::~WoodProducerIterator() {}

/**
 * @brief Construct a new Wood Producer Iterator:: Wood Producer Iterator object
 *
 * @param grid
 */
WoodProducerIterator::WoodProducerIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited WoodProducer
 */
void WoodProducerIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            WoodProducer *producer = dynamic_cast<WoodProducer *>(grid[row][col]);
            if (producer && !isVisited(producer))
            {
                markVisited(producer);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no WoodProducer instances are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited WoodProducer
 */
void WoodProducerIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next WoodProducer in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            WoodProducer *producer = dynamic_cast<WoodProducer *>(grid[row][col]);
            if (producer && !isVisited(producer))
            {
                markVisited(producer);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further WoodProducers, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited WoodProducer
 *
 * @return true if there is another unvisited WoodProducer, false otherwise
 */
bool WoodProducerIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current WoodProducer
 *
 * @return Entity*
 */
Entity *WoodProducerIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
