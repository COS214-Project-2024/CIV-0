#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "entities/base/Entity.h"
#include "utils/EntityType.h"
#include "utils/ConfigManager.h"
#include "utils/Size.h"

/**
 * @class EntityFactory
 * @brief Abstract factory class for creating entities of various types and sizes.
 * 
 * The EntityFactory class serves as a base class to define the interface for creating different
 * types and sizes of entities, including small, medium, and large variants.
 * 
 * @note
 * EntityFactory is an abstract class and cannot be instantiated directly. It requires subclassing, where the 
 * subclass provides concrete implementations for the `createEntity` function.
 */
class EntityFactory
{
public:
    /**
     * @brief Default constructor for EntityFactory.
     */
    EntityFactory();

    /**
     * @brief Virtual destructor for EntityFactory.
     */
    virtual ~EntityFactory();

    /**
     * @brief Pure virtual function to create an entity of a specified type and size at a given position.
     * 
     * Derived classes must implement this function to create a specific type of entity. This allows for 
     * flexible creation of entities, where the exact class of entity created can vary based on the type and size.
     * 
     * @param type The type of entity to create (e.g., Residential, Industrial).
     * @param size The size of the entity to create (small, medium, or large).
     * @param xPos The x-coordinate for the entity's position.
     * @param yPos The y-coordinate for the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos) = 0;
};

#endif // ENTITYFACTORY_H
