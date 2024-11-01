#ifndef SEWAGESYSTEMLEVELTHREEUPGRADE_H
#define SEWAGESYSTEMLEVELTHREEUPGRADE_H

#include "SewageSystemUpgrade.h"

/**
 * @class SewageSystemLevelThreeUpgrade
 * @brief Represents the third level upgrade to a SewageSystem entity.
 *
 * The SewageSystemLevelThreeUpgrade class enhances the base functionality of a SewageSystem by increasing
 * its processing capabilities. This class is the third upgrade level in a series of potential sewage system improvements.
 */
class SewageSystemLevelThreeUpgrade : public SewageSystemUpgrade
{
public:
    /**
     * @brief Constructs a SewageSystemLevelThreeUpgrade object.
     *
     * Initializes the upgrade by enhancing the specified SewageSystem with a level three upgrade.
     *
     * @param sewage Pointer to the original SewageSystem to be upgraded.
     */
    SewageSystemLevelThreeUpgrade(SewageSystem *sewage);

    /**
     * @brief Copy constructor for SewageSystemLevelThreeUpgrade.
     *
     * Creates a new SewageSystemLevelThreeUpgrade object by copying the attributes of an existing
     * SewageSystemLevelThreeUpgrade object.
     * 
     * @param sSLTU Pointer to the existing SewageSystemLevelThreeUpgrade to be copied.
     */
    SewageSystemLevelThreeUpgrade(SewageSystemLevelThreeUpgrade *sSLTU);

    /**
     * @brief Destructor for SewageSystemLevelThreeUpgrade.
     *
     * Cleans up any resources associated with the upgrade.
     */
    ~SewageSystemLevelThreeUpgrade();

    /**
     * @brief Updates the state of the upgraded sewage system.
     *
     * Implements specific behavior for the sewage system after applying the level three upgrade.
     */
    void update();

    /**
     * @brief Clones the current SewageSystemLevelThreeUpgrade object.
     *
     * Creates a new instance of SewageSystemLevelThreeUpgrade with the same attributes as the current object.
     *
     * @return A pointer to the newly cloned SewageSystemLevelThreeUpgrade object.
     */
    Entity *clone();

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade();

    /**
     * @brief Retrieves the upgraded sewage system's output.
     *
     * Returns the processing output of the level three upgraded sewage system.
     *
     * @return The updated processing output as an integer.
     */
    int getOutput();

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    Cost getCost();

    int getLevel() override;

private:
    const int UPGRADE = 6; ///< Multiplier applied to the original processing output for the level three upgrade.
};

#endif // SEWAGESYSTEMLEVELTHREEUPGRADE_H
