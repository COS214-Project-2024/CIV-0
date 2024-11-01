#include "ResidentialBuildingIterator.h"
#include <iostream>

/**
 * @brief Construct a new Residential Building Iterator:: Residential Building Iterator object
 */
ResidentialBuildingIterator::ResidentialBuildingIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Residential Building Iterator:: Residential Building Iterator object
 */
ResidentialBuildingIterator::~ResidentialBuildingIterator() {}

/**
 * @brief Construct a new Residential Building Iterator:: Residential Building Iterator object
 *
 * @param grid
 */
ResidentialBuildingIterator::ResidentialBuildingIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited ResidentialBuilding
 */
void ResidentialBuildingIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            ResidentialBuilding *rBuilding = dynamic_cast<ResidentialBuilding *>(grid[row][col]);
            if (rBuilding && !isVisited(rBuilding))
            {
                markVisited(rBuilding);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no residential buildings are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited ResidentialBuilding
 */
void ResidentialBuildingIterator::next()
{
    if (currRow == grid.end())
        return;

    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            ResidentialBuilding *rBuilding = dynamic_cast<ResidentialBuilding *>(grid[row][col]);
            if (rBuilding && !isVisited(rBuilding))
            {
                markVisited(rBuilding);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further residential buildings, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited ResidentialBuilding
 *
 * @return true if there is another unvisited ResidentialBuilding, false otherwise
 */
bool ResidentialBuildingIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current ResidentialBuilding
 *
 * @return Entity*
 */
Entity *ResidentialBuildingIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
