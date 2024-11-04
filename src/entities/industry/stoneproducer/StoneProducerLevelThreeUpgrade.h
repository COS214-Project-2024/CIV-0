#ifndef STONEPRODUCERLEVELTHREEUPGRADE_H
#define STONEPRODUCERLEVELTHREEUPGRADE_H

#include "StoneProducerUpgrade.h"

/**
 * @class StoneProducerLevelThreeUpgrade
 * @brief Represents a level three upgrade for a stone producer.
 *
 * This class extends the StoneProducerUpgrade class to provide functionality
 * for a level three upgrade of a stone producer.
 */
class StoneProducerLevelThreeUpgrade : public StoneProducerUpgrade
{
public:
    /**
     * @brief Constructs a StoneProducerLevelThreeUpgrade from a given StoneProducer.
     *
     * @param stoneProd Pointer to the StoneProducer to upgrade.
     */
    StoneProducerLevelThreeUpgrade(StoneProducer *stoneProd);

    /**
     * @brief Constructs a StoneProducerLevelThreeUpgrade from another StoneProducerLevelThreeUpgrade instance.
     *
     * @param stoneProd Pointer to the StoneProducerLevelThreeUpgrade to copy.
     */
    StoneProducerLevelThreeUpgrade(StoneProducerLevelThreeUpgrade *stoneProd);

    /**
     * @brief Destructor for the StoneProducerLevelThreeUpgrade class.
     */
    ~StoneProducerLevelThreeUpgrade();

    /**
     * @brief Updates the state of the stone producer upgrade.
     */
    void update() override;

    /**
     * @brief Gets the output of the stone producer upgrade.
     *
     * @return The output value of the upgraded producer.
     */
    int getOutput() override;

    /**
     * @brief Gets the level of the upgrade.
     *
     * @return The level of the upgrade, which is 3 for this class.
     */
    int getLevel() override;

    /**
     * @brief Clones the current StoneProducerLevelThreeUpgrade instance.
     *
     * @return A pointer to a new StoneProducerLevelThreeUpgrade that is a copy of this instance.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the stone producer to the next level.
     *
     * @return A pointer to the next upgraded instance, or nullptr if at the highest level.
     */
    Entity *upgrade() override;

    /**
     * @brief Gets the cost of the stone producer upgrade.
     *
     * @return The cost associated with the upgrade.
     */
    Cost getCost() override;

private:
    const int UPGRADE = 6; ///< Multiplier for the output and cost associated with this upgrade.
};

#endif // STONEPRODUCERLEVELTHREEUPGRADE_H