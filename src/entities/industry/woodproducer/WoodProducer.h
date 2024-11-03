#ifndef WOODPRODUCER_H
#define WOODPRODUCER_H

#include "entities/industry/base/Industry.h"

/**
 * @class WoodProducer
 * @brief Represents a wood producer in the game.
 *
 * The WoodProducer class extends the Industry class to provide functionality
 * for producing wood, which can be upgraded and observed by other entities.
 */
class WoodProducer : public Industry
{
public:
    /**
     * @brief Constructs a WoodProducer with the given configuration.
     *
     * @param ec The configuration for the entity.
     * @param size The size of the wood producer.
     * @param xPos The x position of the wood producer.
     * @param yPos The y position of the wood producer.
     */
    WoodProducer(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the WoodProducer class.
     *
     * @param woodProducer Pointer to the WoodProducer to copy.
     */
    WoodProducer(WoodProducer *woodProducer);

    /**
     * @brief Destructor for the WoodProducer class.
     */
    virtual ~WoodProducer();

    /**
     * @brief Updates the state of the wood producer and notifies observers.
     */
    void update() override;

    /**
     * @brief Clones the current WoodProducer instance.
     *
     * @return A pointer to a new WoodProducer that is a copy of this instance.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the wood producer to the next level.
     *
     * @return A pointer to the upgraded entity, which is a WoodProducerLevelOneUpgrade.
     */
    Entity *upgrade() override;
};

#endif // WOODPRODUCER_H