#ifndef WOODPRODUCERUPGRADE_H
#define WOODPRODUCERUPGRADE_H

#include "WoodProducer.h"

/**
 * @class WoodProducerUpgrade
 * @brief Abstract base class for wood producer upgrades.
 *
 * The WoodProducerUpgrade class extends the WoodProducer class, providing a 
 * framework for creating various upgrades to wood producers.
 */
class WoodProducerUpgrade : public WoodProducer
{
public:
    /**
     * @brief Constructs a WoodProducerUpgrade with the specified wood producer.
     *
     * @param woodProducer Pointer to the wood producer to upgrade.
     */
    WoodProducerUpgrade(WoodProducer *woodProducer);

    /**
     * @brief Destructor for the WoodProducerUpgrade class.
     */
    virtual ~WoodProducerUpgrade();

    /**
     * @brief Copy constructor for the WoodProducerUpgrade class.
     *
     * @param woodProducerUpgrade Pointer to the WoodProducerUpgrade to copy.
     */
    WoodProducerUpgrade(WoodProducerUpgrade *woodProducerUpgrade);

    /**
     * @brief Updates the state of the wood producer upgrade.
     * 
     * This function must be implemented in derived classes.
     */
    virtual void update() = 0;

    /**
     * @brief Gets the output of the wood producer upgrade.
     * 
     * This function must be implemented in derived classes.
     * 
     * @return The output produced by the wood producer upgrade.
     */
    virtual int getOutput() = 0;

    /**
     * @brief Gets the cost of the wood producer upgrade.
     * 
     * This function must be implemented in derived classes.
     * 
     * @return The cost associated with the wood producer upgrade.
     */
    virtual Cost getCost() = 0;

    /**
     * @brief Upgrades the wood producer to the next level.
     * 
     * This function must be implemented in derived classes.
     * 
     * @return A pointer to the upgraded wood producer.
     */
    virtual Entity *upgrade() = 0;

    /**
     * @brief Clones the current WoodProducerUpgrade instance.
     * 
     * This function must be implemented in derived classes.
     * 
     * @return A pointer to a new WoodProducerUpgrade that is a copy of this instance.
     */
    virtual Entity *clone() = 0;

protected:
    WoodProducer *woodProducer; /**< Pointer to the associated wood producer. */
};

#endif // WOODPRODUCERUPGRADE_H