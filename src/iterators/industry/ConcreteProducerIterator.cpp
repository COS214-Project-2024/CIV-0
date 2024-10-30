#include "ConcreteProducerIterator.h"
#include <iostream>

/**
 * @brief Construct a new Concrete Producer Iterator:: Concrete Producer Iterator object
 */
ConcreteProducerIterator::ConcreteProducerIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Concrete Producer Iterator:: Concrete Producer Iterator object
 */
ConcreteProducerIterator::~ConcreteProducerIterator() {}

/**
 * @brief Construct a new Concrete Producer Iterator:: Concrete Producer Iterator object
 *
 * @param grid
 */
ConcreteProducerIterator::ConcreteProducerIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited ConcreteProducer
 *
 */
void ConcreteProducerIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            ConcreteProducer *producer = dynamic_cast<ConcreteProducer *>(grid[row][col]);
            if (producer && !isVisited(producer))
            {
                markVisited(producer);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no concrete producers are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited ConcreteProducer
 *
 */
void ConcreteProducerIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next concrete producer in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            ConcreteProducer *producer = dynamic_cast<ConcreteProducer *>(grid[row][col]);
            if (producer && !isVisited(producer))
            {
                markVisited(producer);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further concrete producers, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited ConcreteProducer
 *
 * @return true if there is another unvisited ConcreteProducer, false otherwise
 */
bool ConcreteProducerIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current ConcreteProducer
 *
 * @return Entity*
 */
Entity *ConcreteProducerIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
