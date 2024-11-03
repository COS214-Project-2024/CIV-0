#ifndef WOODPRODUCERLEVELTHREEUPGRADE_H
#define WOODPRODUCERLEVELTHREEUPGRADE_H

#include "WoodProducerUpgrade.h"

/**
 * @class WoodProducerLevelThreeUpgrade
 * @brief Class representing the third upgrade level for a wood producer.
 *
 * The WoodProducerLevelThreeUpgrade class is a concrete implementation of
 * WoodProducerUpgrade, providing functionality for the third level of 
 * upgrade for wood producers.
 */
class WoodProducerLevelThreeUpgrade : public WoodProducerUpgrade
{
public:
    /**
     * @brief Constructs a WoodProducerLevelThreeUpgrade with the specified wood producer.
     *
     * @param woodProd Pointer to the wood producer to upgrade.
     */
    WoodProducerLevelThreeUpgrade(WoodProducer *woodProd);

    /**
     * @brief Copy constructor for WoodProducerLevelThreeUpgrade.
     *
     * @param woodProd Pointer to the WoodProducerLevelThreeUpgrade to copy.
     */
    WoodProducerLevelThreeUpgrade(WoodProducerLevelThreeUpgrade *woodProd);

    /**
     * @brief Destructor for the WoodProducerLevelThreeUpgrade class.
     */
    ~WoodProducerLevelThreeUpgrade();

    /**
     * @brief Updates the state of the wood producer upgrade.
     */
    void update() override;

    /**
     * @brief Clones the current WoodProducerLevelThreeUpgrade instance.
     *
     * @return A pointer to a new WoodProducerLevelThreeUpgrade that is a copy of this instance.
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
     * @brief Upgrades the wood producer to the next level (no further upgrade).
     *
     * @return nullptr as there are no further upgrades.
     */
    Entity *upgrade() override;

    /**
     * @brief Gets the cost of the wood producer upgrade.
     *
     * @return The cost associated with the wood producer upgrade.
     */
    Cost getCost() override;

private:
    const int UPGRADE = 6; /**< Upgrade multiplier for output and cost. */
};

#endif // WOODPRODUCERLEVELTHREEUPGRADE_H