#include "Iterator.h"

/**
 * @brief Construct a new Iterator object, initializing row and column to zero.
 */
Iterator::Iterator()
{
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Iterator object.
 */
Iterator::~Iterator() {}

/**
 * @brief Get the current row index of the iterator.
 *
 * @return int The current row index.
 */
int Iterator::getRow() { return this->row; }

/**
 * @brief Get the current column index of the iterator.
 *
 * @return int The current column index.
 */
int Iterator::getCol() { return this->col; }

/**
 * @brief Check if the specified entity has been visited.
 *
 * @param entity Pointer to the entity to check.
 * @return true if the entity has been visited; false otherwise.
 */
bool Iterator::isVisited(Entity *entity)
{
    return visitedEntities.find(entity) != visitedEntities.end();
}

/**
 * @brief Mark the specified entity as visited.
 *
 * @param entity Pointer to the entity to mark as visited.
 */
void Iterator::markVisited(Entity *entity)
{
    visitedEntities.insert(entity);
}