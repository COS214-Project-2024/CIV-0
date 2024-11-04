#ifndef WOODPRODUCERLEVELTWOUPGRADE_H
#define WOODPRODUCERLEVELTWOUPGRADE_H

#include "WoodProducerUpgrade.h"

/**
 * @class WoodProducerLevelTwoUpgrade
 * @brief Class representing the second upgrade level for a wood producer.
 *
 * The WoodProducerLevelTwoUpgrade class is a concrete implementation of
 * WoodProducerUpgrade, providing functionality for the second level of 
 * upgrade for wood producers.
 */
class WoodProducerLevelTwoUpgrade : public WoodProducerUpgrade
{
public:
    /**
     * @brief Constructs a WoodProducerLevelTwoUpgrade with the specified wood producer.
     *
     * @param woodProducer Pointer to the wood producer to upgrade.
     */
    WoodProducerLevelTwoUpgrade(WoodProducer *woodProducer);

    /**
     * @brief Copy constructor for WoodProducerLevelTwoUpgrade.
     *
     * @param woodProd Pointer to the WoodProducerLevelTwoUpgrade to copy.
     */
    WoodProducerLevelTwoUpgrade(WoodProducerLevelTwoUpgrade *woodProd);

    /**
     * @brief Destructor for the WoodProducerLevelTwoUpgrade class.
     */
    ~WoodProducerLevelTwoUpgrade();

    /**
     * @brief Updates the state of the wood producer upgrade.
     */
    void update() override;

    /**
     * @brief Clones the current WoodProducerLevelTwoUpgrade instance.
     *
     * @return A pointer to a new WoodProducerLevelTwoUpgrade that is a copy of this instance.
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
    const int UPGRADE = 4; /**< Upgrade multiplier for output and cost. */
};

#endif // WOODPRODUCERLEVELTWOUPGRADE_H