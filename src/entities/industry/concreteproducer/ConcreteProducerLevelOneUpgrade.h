#ifndef CONCRETEPRODUCERLEVELONEUPGRADE_H
#define CONCRETEPRODUCERLEVELONEUPGRADE_H

#include "entities/industry/concreteproducer/ConcreteProducerUpgrade.h"

/**
 * @class ConcreteProducerLevelOneUpgrade
 * @brief Represents the level one upgrade of a ConcreteProducer entity.
 *
 * This class extends ConcreteProducerUpgrade to provide specific behavior and
 * properties for the first level upgrade of the concrete producer.
 */
class ConcreteProducerLevelOneUpgrade : public ConcreteProducerUpgrade
{
public:
    /**
     * @brief Constructs a ConcreteProducerLevelOneUpgrade from a ConcreteProducer instance.
     *
     * @param concreteProd Pointer to the ConcreteProducer to be upgraded.
     */
    ConcreteProducerLevelOneUpgrade(ConcreteProducer *concreteProd);

    /**
     * @brief Copy constructor for the ConcreteProducerLevelOneUpgrade class.
     *
     * Creates a new ConcreteProducerLevelOneUpgrade by copying an existing instance.
     *
     * @param concreteProd Pointer to the ConcreteProducerLevelOneUpgrade object to be copied.
     */
    ConcreteProducerLevelOneUpgrade(ConcreteProducerLevelOneUpgrade *concreteProd);

    /**
     * @brief Destructor for the ConcreteProducerLevelOneUpgrade class.
     */
    ~ConcreteProducerLevelOneUpgrade();

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
     * @return The level of the upgrade, which is 1 for this class.
     */
    int getLevel() override;

    /**
     * @brief Creates a clone of the ConcreteProducerLevelOneUpgrade entity.
     *
     * @return A pointer to the cloned ConcreteProducerLevelOneUpgrade instance.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the current concrete producer to the next level.
     *
     * @return A pointer to the upgraded entity, specifically a ConcreteProducerLevelTwoUpgrade.
     */
    Entity *upgrade() override;

    /**
     * @brief Gets the cost of upgrading to the next level.
     *
     * @return The cost associated with the level one upgrade.
     */
    Cost getCost() override;

private:
    const int UPGRADE = 2; ///< Multiplier for output and cost associated with the upgrade.
};

#endif // CONCRETEPRODUCERLEVELONEUPGRADE_H