#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H
#include "entities/base/Entity.h"
#include "utils/EntityType.h"
#include "utils/ConfigManager.h"
#include "utils/Size.h"
/**
 * @class EntityFactory
 * @brief Abstract factory class for creating entities of various sizes.
 *
 * The EntityFactory class provides an interface for creating entities of different sizes: small, medium, and large.
 * This class follows the Factory Design Pattern, allowing for the creation of entities without specifying the exact class of object that will be created.
 * Derived classes must implement the creation methods for different entity types and sizes.
 * 
 * @details
 * - createSmallEntity: Creates a small entity of the specified type at the given position.
 * - createMediumEntity: Creates a medium entity of the specified type at the given position.
 * - createLargeEntity: Creates a large entity of the specified type at the given position.
 * 
 * @note
 * This class is abstract and cannot be instantiated directly. It must be subclassed, and the subclass must provide implementations for the pure virtual methods.
 */
class EntityFactory
{
public:
    EntityFactory();
    ~EntityFactory();
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos) = 0;
};

#endif