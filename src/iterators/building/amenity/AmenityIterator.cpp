#include "AmenityIterator.h"
#include <iostream>

/**
 * @brief Construct a new Amenity Iterator:: Amenity Iterator object
 *
 */
AmenityIterator::AmenityIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Amenity Iterator:: Amenity Iterator object
 *
 */
AmenityIterator::~AmenityIterator() {}

/**
 * @brief Construct a new Amenity Iterator:: Amenity Iterator object
 *
 * @param grid
 */
AmenityIterator::AmenityIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited Amenity
 *
 */
void AmenityIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            Amenity *amenity = dynamic_cast<Amenity *>(grid[row][col]);
            if (amenity && !isVisited(amenity))
            {
                markVisited(amenity);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no amenities are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited Amenity
 *
 */
void AmenityIterator::next()
{
    if (currRow == grid.end())
        return;

    // Find the next amenity in the grid
    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            Amenity *amenity = dynamic_cast<Amenity *>(grid[row][col]);
            if (amenity && !isVisited(amenity))
            {
                markVisited(amenity);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further amenities, set iterator to the endz
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited Amenity
 *
 * @return true if there is another unvisited Amenity, false otherwise
 */
bool AmenityIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current Amenity
 *
 * @return Entity*
 */
Entity *AmenityIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
