#ifndef STONEPRODUCERLEVELONEUPGRADE_H
#define STONEPRODUCERLEVELONEUPGRADE_H

#include "StoneProducerUpgrade.h"

/**
 * @class StoneProducerLevelOneUpgrade
 * @brief Represents a level one upgrade for a stone producer.
 *
 * This class extends the StoneProducerUpgrade class to provide functionality
 * for a level one upgrade of a stone producer.
 */
class StoneProducerLevelTwoUgprade; // Typo: "Ugprade" should be "Upgrade."

class StoneProducerLevelOneUpgrade : public StoneProducerUpgrade
{
public:
    /**
     * @brief Constructs a StoneProducerLevelOneUpgrade from a given StoneProducer.
     *
     * @param stoneProd Pointer to the StoneProducer to upgrade.
     */
    StoneProducerLevelOneUpgrade(StoneProducer *stoneProd);

    /**
     * @brief Constructs a StoneProducerLevelOneUpgrade from another StoneProducerLevelOneUpgrade instance.
     *
     * @param stoneProd Pointer to the StoneProducerLevelOneUpgrade to copy.
     */
    StoneProducerLevelOneUpgrade(StoneProducerLevelOneUpgrade *stoneProd);

    /**
     * @brief Destructor for the StoneProducerLevelOneUpgrade class.
     */
    ~StoneProducerLevelOneUpgrade();

    /**
     * @brief Gets the output of the stone producer upgrade.
     *
     * @return The output value of the upgraded producer.
     */
    int getOutput() override;

    /**
     * @brief Gets the level of the upgrade.
     *
     * @return The level of the upgrade, which is 1 for this class.
     */
    int getLevel() override;

    /**
     * @brief Clones the current StoneProducerLevelOneUpgrade instance.
     *
     * @return A pointer to a new StoneProducerLevelOneUpgrade that is a copy of this instance.
     */
    Entity *clone() override;

    /**
     * @brief Updates the state of the stone producer upgrade.
     */
    void update() override;

    /**
     * @brief Upgrades the stone producer to the next level.
     *
     * @return A pointer to the upgraded StoneProducerLevelTwoUpgrade instance.
     */
    Entity *upgrade() override;

    /**
     * @brief Gets the cost of the stone producer upgrade.
     *
     * @return The cost associated with the upgrade.
     */
    Cost getCost() override;

private:
    const int UPGRADE = 2; ///< Multiplier for the output and cost associated with this upgrade.
};

#endif // STONEPRODUCERLEVELONEUPGRADE_H
