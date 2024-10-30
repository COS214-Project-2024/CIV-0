#include "PowerPlantIterator.h"

/**
 * @brief Construct a new PowerPlantIterator object
 */
PowerPlantIterator::PowerPlantIterator() : Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the PowerPlantIterator object
 */
PowerPlantIterator::~PowerPlantIterator() {}

/**
 * @brief Construct a new PowerPlantIterator object with grid
 *
 * @param grid
 */
PowerPlantIterator::PowerPlantIterator(std::vector<std::vector<Entity *>> &grid) : Iterator(grid)
{
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
    first();
}

/**
 * @brief Sets the iterator to the first unvisited PowerPlant
 */
void PowerPlantIterator::first()
{
    visitedEntities.clear(); // Clear visited set for reuse
    row = 0;
    col = 0;

    for (row = 0; row < grid.size(); ++row)
    {
        for (col = 0; col < grid[row].size(); ++col)
        {
            PowerPlant *plant = dynamic_cast<PowerPlant *>(grid[row][col]);
            if (plant && !isVisited(plant))
            {
                markVisited(plant);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // Set to end if no PowerPlant instances are found
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Advances to the next unvisited PowerPlant
 */
void PowerPlantIterator::next()
{
    if (currRow == grid.end())
        return;

    for (++col; row < grid.size(); ++row, col = 0)
    {
        for (; col < grid[row].size(); ++col)
        {
            PowerPlant *plant = dynamic_cast<PowerPlant *>(grid[row][col]);
            if (plant && !isVisited(plant))
            {
                markVisited(plant);
                currRow = grid.begin() + row;
                curr = currRow->begin() + col;
                return;
            }
        }
    }

    // If no further PowerPlants, set iterator to the end
    currRow = grid.end();
    curr = {};
}

/**
 * @brief Checks if there is another unvisited PowerPlant
 *
 * @return true if there is another unvisited PowerPlant, false otherwise
 */
bool PowerPlantIterator::hasNext()
{
    return currRow != grid.end() && curr != currRow->end();
}

/**
 * @brief Returns the current PowerPlant
 *
 * @return Entity*
 */
Entity *PowerPlantIterator::current()
{
    return (currRow != grid.end() && curr != currRow->end()) ? *curr : nullptr;
}
