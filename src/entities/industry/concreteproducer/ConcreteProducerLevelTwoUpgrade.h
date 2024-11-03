#ifndef CONCRETEPRODUCERLEVELTWOUPGRADE_H
#define CONCRETEPRODUCERLEVELTWOUPGRADE_H

#include "entities/industry/concreteproducer/ConcreteProducerUpgrade.h"

/**
 * @class ConcreteProducerLevelTwoUpgrade
 * @brief Represents the level two upgrade of a ConcreteProducer entity.
 *
 * This class extends ConcreteProducerUpgrade to provide specific behavior and
 * properties for the second level upgrade of the concrete producer.
 */
class ConcreteProducerLevelTwoUpgrade : public ConcreteProducerUpgrade
{
public:
    /**
     * @brief Constructs a ConcreteProducerLevelTwoUpgrade from a ConcreteProducer instance.
     *
     * @param concreteProd Pointer to the ConcreteProducer to be upgraded.
     */
    ConcreteProducerLevelTwoUpgrade(ConcreteProducer *concreteProd);

    /**
     * @brief Copy constructor for the ConcreteProducerLevelTwoUpgrade class.
     *
     * Creates a new ConcreteProducerLevelTwoUpgrade by copying an existing instance.
     *
     * @param concreteProd Pointer to the ConcreteProducerLevelTwoUpgrade object to be copied.
     */
    ConcreteProducerLevelTwoUpgrade(ConcreteProducerLevelTwoUpgrade *concreteProd);

    /**
     * @brief Destructor for the ConcreteProducerLevelTwoUpgrade class.
     */
    ~ConcreteProducerLevelTwoUpgrade();

    /**
     * @brief Updates the state of the concrete producer.
     *
     * This method invokes the update on the associated concrete producer.
     */
    void update() override;

    /**
     * @brief Gets the output production of the upgraded concrete producer.
     *
     * @return The production output value after applying the upgrade multiplier.
     */
    int getOutput() override;

    /**
     * @brief Gets the upgrade level of the concrete producer.
     *
     * @return The level of the upgrade, which is 2 for this class.
     */
    int getLevel() override;

    /**
     * @brief Creates a clone of the ConcreteProducerLevelTwoUpgrade entity.
     *
     * @return A pointer to the cloned ConcreteProducerLevelTwoUpgrade instance.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the current concrete producer to the next level.
     *
     * @return A pointer to the upgraded entity, specifically a ConcreteProducerLevelThreeUpgrade.
     */
    Entity *upgrade() override;

    /**
     * @brief Gets the cost of upgrading to the next level.
     *
     * @return The cost associated with the level two upgrade.
     */
    Cost getCost() override;

private:
    const int UPGRADE = 4; ///< Multiplier for output and cost associated with the upgrade.
};

#endif // CONCRETEPRODUCERLEVELTWOUPGRADE_H
