#ifndef STONEPRODUCER_H
#define STONEPRODUCER_H

#include "entities/industry/base/Industry.h"

/**
 * @class StoneProducer
 * @brief Represents a stone producer entity in the industry.
 *
 * This class is responsible for producing stone resources and managing its state.
 */
class StoneProducer : public Industry
{
public:
    /**
     * @brief Constructs a StoneProducer from another StoneProducer instance.
     *
     * @param stoneProducer Pointer to the StoneProducer to copy.
     */
    StoneProducer(StoneProducer *stoneProducer);

    /**
     * @brief Constructs a StoneProducer with specified configuration and position.
     *
     * @param ec Entity configuration for the stone producer.
     * @param size Size of the producer entity.
     * @param xPos X position in the grid.
     * @param yPos Y position in the grid.
     */
    StoneProducer(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Destructor for the StoneProducer class.
     */
    virtual ~StoneProducer();

    /**
     * @brief Updates the state of the stone producer.
     *
     * This method notifies observers and updates the build state if necessary.
     */
    void update() override;

    /**
     * @brief Clones the current StoneProducer instance.
     *
     * @return A pointer to a new StoneProducer that is a copy of this instance.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the stone producer to the next level.
     *
     * @return A pointer to the upgraded StoneProducerLevelOneUpgrade instance.
     */
    Entity *upgrade() override;
};

#endif // STONEPRODUCER_H