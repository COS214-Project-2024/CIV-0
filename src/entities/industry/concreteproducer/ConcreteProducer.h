#ifndef CONCRETEPRODUCER_H
#define CONCRETEPRODUCER_H

#include "entities/industry/base/Industry.h"

class ConcreteProducerLevelOneUpgrade;

/**
 * @class ConcreteProducer
 * @brief Represents a concrete producer industry entity.
 *
 * This class manages the concrete production process and interacts with
 * residential buildings in the game.
 */
class ConcreteProducer : public Industry
{
public:
    /**
     * @brief Constructs a ConcreteProducer entity with specified attributes.
     *
     * @param ec Configuration settings for the entity.
     * @param size Size of the concrete producer entity.
     * @param xPos X-coordinate position of the entity.
     * @param yPos Y-coordinate position of the entity.
     */
    ConcreteProducer(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the ConcreteProducer class.
     *
     * Creates a new ConcreteProducer entity by copying the attributes of an existing ConcreteProducer.
     *
     * @param concreteProducer Pointer to the ConcreteProducer object to be copied.
     */
    ConcreteProducer(ConcreteProducer *concreteProducer);

    /**
     * @brief Virtual destructor for the ConcreteProducer class.
     */
    virtual ~ConcreteProducer();

    /**
     * @brief Updates the state of the concrete producer.
     *
     * This method notifies residential buildings of changes and updates the build state if necessary.
     */
    void update() override;

    /**
     * @brief Creates a clone of the ConcreteProducer entity.
     *
     * @return A pointer to the cloned ConcreteProducer entity.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the current ConcreteProducer to the next level.
     *
     * @return A pointer to the upgraded ConcreteProducerLevelOneUpgrade instance.
     */
    Entity *upgrade() override;
};

#endif // CONCRETEPRODUCER_H