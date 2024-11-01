#ifndef INDUSTRYFACTORY_H
#define INDUSTRYFACTORY_H

#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/industry/stoneproducer/StoneProducer.h"
#include "entities/industry/woodproducer/WoodProducer.h"
#include "factory/base/EntityFactory.h"

/**
 * @class IndustryFactory
 * @brief Factory class for creating industrial entities such as concrete, stone, and wood producers.
 *
 * This class inherits from EntityFactory and provides methods to create various-sized industrial
 * entities (small, medium, and large) at specific positions in the environment.
 */
class IndustryFactory : public EntityFactory {
   public:
    /**
     * @brief Default constructor for IndustryFactory.
     */
    IndustryFactory();

    /**
     * @brief Destructor for IndustryFactory.
     */
    ~IndustryFactory();

    /**
     * @brief Creates an industrial entity of a specified type and size at the given coordinates.
     *
     * @param type The type of industrial entity to create (e.g., ConcreteProducer, StoneProducer, WoodProducer).
     * @param size The size of the entity (small, medium, or large).
     * @param xPos The x-coordinate for the entity's position.
     * @param yPos The y-coordinate for the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos);

   private:
    /**
     * @brief Creates a concrete producer of the specified size at a given position.
     *
     * @param size Size of the concrete producer (small, medium, or large).
     * @param xPos X-coordinate for the concrete producer's position.
     * @param yPos Y-coordinate for the concrete producer's position.
     * @return A pointer to the created ConcreteProducer entity.
     */
    Entity* createConcreteProducer(Size size, int xPos, int yPos);

    /**
     * @brief Creates a stone producer of the specified size at a given position.
     *
     * @param size Size of the stone producer (small, medium, or large).
     * @param xPos X-coordinate for the stone producer's position.
     * @param yPos Y-coordinate for the stone producer's position.
     * @return A pointer to the created StoneProducer entity.
     */
    Entity* createStoneProducer(Size size, int xPos, int yPos);

    /**
     * @brief Creates a wood producer of the specified size at a given position.
     *
     * @param size Size of the wood producer (small, medium, or large).
     * @param xPos X-coordinate for the wood producer's position.
     * @param yPos Y-coordinate for the wood producer's position.
     * @return A pointer to the created WoodProducer entity.
     */
    Entity* createWoodProducer(Size size, int xPos, int yPos);
};

#endif // INDUSTRYFACTORY_H
