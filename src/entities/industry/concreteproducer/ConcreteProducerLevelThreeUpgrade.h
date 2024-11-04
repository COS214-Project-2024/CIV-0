#ifndef CONCRETEPRODUCERLEVELTHREEUPGRADE_H
#define CONCRETEPRODUCERLEVELTHREEUPGRADE_H

#include "entities/industry/concreteproducer/ConcreteProducerUpgrade.h"

/**
 * @class ConcreteProducerLevelThreeUpgrade
 * @brief Represents the level three upgrade of a ConcreteProducer entity.
 *
 * This class extends ConcreteProducerUpgrade to provide specific behavior and
 * properties for the third level upgrade of the concrete producer.
 */
class ConcreteProducerLevelThreeUpgrade : public ConcreteProducerUpgrade
{
public:
    /**
     * @brief Constructs a ConcreteProducerLevelThreeUpgrade from a ConcreteProducer instance.
     *
     * @param concreteProd Pointer to the ConcreteProducer to be upgraded.
     */
    ConcreteProducerLevelThreeUpgrade(ConcreteProducer *concreteProd);

    /**
     * @brief Copy constructor for the ConcreteProducerLevelThreeUpgrade class.
     *
     * Creates a new ConcreteProducerLevelThreeUpgrade by copying an existing instance.
     *
     * @param concreteProd Pointer to the ConcreteProducerLevelThreeUpgrade object to be copied.
     */
    ConcreteProducerLevelThreeUpgrade(ConcreteProducerLevelThreeUpgrade *concreteProd);

    /**
     * @brief Destructor for the ConcreteProducerLevelThreeUpgrade class.
     */
    ~ConcreteProducerLevelThreeUpgrade();

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
     * @return The level of the upgrade, which is 3 for this class.
     */
    int getLevel() override;

    /**
     * @brief Creates a clone of the ConcreteProducerLevelThreeUpgrade entity.
     *
     * @return A pointer to the cloned ConcreteProducerLevelThreeUpgrade instance.
     */
    Entity *clone() override;

    /**
     * @brief Gets the cost of upgrading to the next level.
     *
     * @return The cost associated with the level three upgrade.
     */
    Cost getCost() override;

    /**
     * @brief Upgrades the current concrete producer to the next level.
     *
     * @return nullptr, as this is the final upgrade level.
     */
    Entity *upgrade() override;

private:
    const int UPGRADE = 6; ///< Multiplier for output and cost associated with the upgrade.
};

#endif // CONCRETEPRODUCERLEVELTHREEUPGRADE_H