#ifndef INDUSTRYFACTORY_H
#define INDUSTRYFACTORY_H

#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/industry/stoneproducer/StoneProducer.h"
#include "entities/industry/woodproducer/WoodProducer.h"
#include "factory/base/EntityFactory.h"

/**
 * @class IndustryFactory
 * @brief A factory class for creating industrial entities like concrete, stone, and wood producers.
 *
 * This class inherits from EntityFactory and provides methods for creating small, medium,
 * and large industrial entities of different types.
 */
class IndustryFactory : public EntityFactory {
   public:
	/**
	 * @brief Constructor for the IndustryFactory class.
	 */
	IndustryFactory();

	/**
	 * @brief Destructor for the IndustryFactory class.
	 */
	~IndustryFactory();

	/**
	 * @brief Creates a small industrial entity of the specified type at the given position.
	 *
	 * @param type The type of industrial entity to create.
	 * @param xPos The x-coordinate of the entity's position.
	 * @param yPos The y-coordinate of the entity's position.
	 * @return A pointer to the created Entity.
	 */
	virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos);

   private:
	/**
	 * @brief Creates a concrete producer of the specified size at the given position.
	 *
	 * @param size The size of the concrete producer to create.
	 * @param xPos The x-coordinate of the producer's position.
	 * @param yPos The y-coordinate of the producer's position.
	 * @return A pointer to the created Entity.
	 */
	Entity* createConcreteProducer(Size size, int xPos, int yPos);

	/**
	 * @brief Creates a stone producer of the specified size at the given position.
	 *
	 * @param size The size of the stone producer to create.
	 * @param xPos The x-coordinate of the producer's position.
	 * @param yPos The y-coordinate of the producer's position.
	 * @return A pointer to the created Entity.
	 */
	Entity* createStoneProducer(Size size, int xPos, int yPos);

	/**
	 * @brief Creates a wood producer of the specified size at the given position.
	 *
	 * @param size The size of the wood producer to create.
	 * @param xPos The x-coordinate of the producer's position.
	 * @param yPos The y-coordinate of the producer's position.
	 * @return A pointer to the created Entity.
	 */
	Entity* createWoodProducer(Size size, int xPos, int yPos);
};

#endif	// INDUSTRYFACTORY_H
