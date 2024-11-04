#ifndef CONCRETEPRODUCERUPGRADE_H
#define CONCRETEPRODUCERUPGRADE_H

class ConcreteProducer;

#include "ConcreteProducer.h"

/**
 * @class ConcreteProducerUpgrade
 * @brief Base class for upgrades of the ConcreteProducer entity.
 *
 * This class serves as a base for different levels of upgrades for the 
 * ConcreteProducer, managing shared properties and methods.
 */
class ConcreteProducerUpgrade : public ConcreteProducer
{
public:
    /**
     * @brief Constructs a ConcreteProducerUpgrade from a ConcreteProducer instance.
     *
     * @param concreteProd Pointer to the ConcreteProducer to be upgraded.
     */
    ConcreteProducerUpgrade(ConcreteProducer *concreteProd);

    /**
     * @brief Copy constructor for the ConcreteProducerUpgrade class.
     *
     * Creates a new ConcreteProducerUpgrade by copying an existing instance.
     *
     * @param concreteProd Pointer to the ConcreteProducerUpgrade object to be copied.
     */
    ConcreteProducerUpgrade(ConcreteProducerUpgrade *concreteProd);

    /**
     * @brief Virtual destructor for the ConcreteProducerUpgrade class.
     */
    virtual ~ConcreteProducerUpgrade();

    /**
     * @brief Gets the production output of the upgraded concrete producer.
     *
     * @return The production output value.
     */
    virtual int getOutput() = 0;

    /**
     * @brief Creates a clone of the upgraded concrete producer.
     *
     * @return A pointer to the cloned ConcreteProducerUpgrade entity.
     */
    virtual Entity *clone() = 0;

    /**
     * @brief Updates the state of the upgraded concrete producer.
     *
     * This method must be implemented in derived classes.
     */
    virtual void update() = 0;

    /**
     * @brief Gets the cost of upgrading the concrete producer.
     *
     * @return The cost associated with the upgrade.
     */
    virtual Cost getCost() = 0;

    /**
     * @brief Upgrades the current concrete producer upgrade to the next level.
     *
     * @return A pointer to the upgraded entity, or nullptr if at maximum level.
     */
    virtual Entity* upgrade() = 0;

protected:
    ConcreteProducer *concreteProducer; ///< Pointer to the associated ConcreteProducer instance.
};

#endif // CONCRETEPRODUCERUPGRADE_H