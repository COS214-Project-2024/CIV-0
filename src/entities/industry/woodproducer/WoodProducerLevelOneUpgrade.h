#ifndef WOODPRODUCERLEVELONEUPGRADE_H
#define WOODPRODUCERLEVELONEUPGRADE_H

#include "WoodProducerUpgrade.h"

/**
 * @class WoodProducerLevelOneUpgrade
 * @brief Class representing the first upgrade level for a wood producer.
 *
 * The WoodProducerLevelOneUpgrade class is a concrete implementation of
 * WoodProducerUpgrade, providing functionality for the first level of 
 * upgrade for wood producers.
 */
class WoodProducerLevelOneUpgrade : public WoodProducerUpgrade
{
public:
    /**
     * @brief Constructs a WoodProducerLevelOneUpgrade with the specified wood producer.
     *
     * @param woodProducer Pointer to the wood producer to upgrade.
     */
    WoodProducerLevelOneUpgrade(WoodProducer *woodProducer);

    /**
     * @brief Copy constructor for WoodProducerLevelOneUpgrade.
     *
     * @param woodprod Pointer to the WoodProducerLevelOneUpgrade to copy.
     */
    WoodProducerLevelOneUpgrade(WoodProducerLevelOneUpgrade *woodprod);

    /**
     * @brief Destructor for the WoodProducerLevelOneUpgrade class.
     */
    ~WoodProducerLevelOneUpgrade();

    /**
     * @brief Updates the state of the wood producer upgrade.
     */
    void update() override;

    /**
     * @brief Clones the current WoodProducerLevelOneUpgrade instance.
     *
     * @return A pointer to a new WoodProducerLevelOneUpgrade that is a copy of this instance.
     */
    Entity *clone() override;

    /**
     * @brief Gets the output of the wood producer upgrade.
     *
     * @return The output produced by the wood producer upgrade.
     */
    int getOutput() override;

    /**
     * @brief Gets the level of the wood producer upgrade.
     *
     * @return The level of the wood producer upgrade.
     */
    int getLevel() override;

    /**
     * @brief Upgrades the wood producer to the next level.
     *
     * @return A pointer to the upgraded wood producer.
     */
    Entity *upgrade() override;

    /**
     * @brief Gets the cost of the wood producer upgrade.
     *
     * @return The cost associated with the wood producer upgrade.
     */
    Cost getCost() override;

private:
    const int UPGRADE = 2; /**< Upgrade multiplier for output and cost. */
};

#endif // WOODPRODUCERLEVELONEUPGRADE_H