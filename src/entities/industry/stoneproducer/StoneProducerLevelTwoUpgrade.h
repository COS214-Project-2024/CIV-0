#ifndef STONEPRODUCERLEVELTWOUPGRADE_H
#define STONEPRODUCERLEVELTWOUPGRADE_H

#include "StoneProducerUpgrade.h"

/**
 * @class StoneProducerLevelTwoUpgrade
 * @brief Represents a level two upgrade for a stone producer.
 *
 * This class extends the StoneProducerUpgrade class to provide functionality
 * for a level two upgrade of a stone producer.
 */
class StoneProducerLevelThreeUpgrade; // Forward declaration for level three upgrade.

class StoneProducerLevelTwoUpgrade : public StoneProducerUpgrade
{
public:
    /**
     * @brief Constructs a StoneProducerLevelTwoUpgrade from a given StoneProducer.
     *
     * @param stoneProd Pointer to the StoneProducer to upgrade.
     */
    StoneProducerLevelTwoUpgrade(StoneProducer *stoneProd);

    /**
     * @brief Constructs a StoneProducerLevelTwoUpgrade from another StoneProducerLevelTwoUpgrade instance.
     *
     * @param stoneProd Pointer to the StoneProducerLevelTwoUpgrade to copy.
     */
    StoneProducerLevelTwoUpgrade(StoneProducerLevelTwoUpgrade *stoneProd);

    /**
     * @brief Destructor for the StoneProducerLevelTwoUpgrade class.
     */
    ~StoneProducerLevelTwoUpgrade();

    /**
     * @brief Clones the current StoneProducerLevelTwoUpgrade instance.
     *
     * @return A pointer to a new StoneProducerLevelTwoUpgrade that is a copy of this instance.
     */
    Entity *clone() override;

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
     * @return The level of the upgrade, which is 2 for this class.
     */
    int getLevel() override;

    /**
     * @brief Upgrades the stone producer to the next level.
     *
     * @return A pointer to the upgraded StoneProducerLevelThreeUpgrade instance.
     */
    Entity *upgrade() override;

    /**
     * @brief Gets the cost of the stone producer upgrade.
     *
     * @return The cost associated with the upgrade.
     */
    Cost getCost() override;

private:
    const int UPGRADE = 4; ///< Multiplier for the output and cost associated with this upgrade.
};

#endif // STONEPRODUCERLEVELTWOUPGRADE_H