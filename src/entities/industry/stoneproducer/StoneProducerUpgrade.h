#ifndef STONEPRODUCERUPGRADE_H
#define STONEPRODUCERUPGRADE_H

#include "StoneProducer.h"

/**
 * @class StoneProducerUpgrade
 * @brief Abstract base class for stone producer upgrades.
 *
 * This class provides a common interface for various upgrades of stone producers.
 */
class StoneProducerUpgrade : public StoneProducer
{
public:
    /**
     * @brief Constructs a StoneProducerUpgrade from a given StoneProducer.
     *
     * @param stoneProd Pointer to the StoneProducer to upgrade.
     */
    StoneProducerUpgrade(StoneProducer *stoneProd);

    /**
     * @brief Constructs a StoneProducerUpgrade from another StoneProducerUpgrade instance.
     *
     * @param stoneProd Pointer to the StoneProducerUpgrade to copy.
     */
    StoneProducerUpgrade(StoneProducerUpgrade *stoneProd);

    /**
     * @brief Destructor for the StoneProducerUpgrade class.
     */
    virtual ~StoneProducerUpgrade();

    /**
     * @brief Updates the state of the stone producer upgrade.
     *
     * This method is implemented by derived classes.
     */
    virtual void update() = 0;

    /**
     * @brief Clones the current StoneProducerUpgrade instance.
     *
     * @return A pointer to a new StoneProducerUpgrade that is a copy of this instance.
     */
    virtual Entity *clone() = 0;

    /**
     * @brief Gets the output of the stone producer upgrade.
     *
     * @return The output value of the upgraded producer.
     */
    virtual int getOutput() = 0;

    /**
     * @brief Upgrades the stone producer to the next level.
     *
     * @return A pointer to the upgraded StoneProducer instance.
     */
    virtual Entity* upgrade() = 0;

    /**
     * @brief Gets the cost of the stone producer upgrade.
     *
     * @return The cost associated with the upgrade.
     */
    virtual Cost getCost() = 0;

protected:
    StoneProducer *stoneProducer; ///< Pointer to the base stone producer being upgraded.
};

#endif // STONEPRODUCERUPGRADE_H