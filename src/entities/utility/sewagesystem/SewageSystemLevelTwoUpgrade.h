#ifndef SEWAGESYSTEMLEVELTWOUPGRADE_H
#define SEWAGESYSTEMLEVELTWOUPGRADE_H

#include "SewageSystemUpgrade.h"

class SewageSystemLevelThreeUpgrade;

/**
 * @class SewageSystemLevelTwoUpgrade
 * @brief Represents the second level upgrade to a SewageSystem entity.
 *
 * The SewageSystemLevelTwoUpgrade class enhances the base functionality of a SewageSystem by increasing
 * its output. This class is the second upgrade level in a series of potential sewage system improvements.
 */
class SewageSystemLevelTwoUpgrade : public SewageSystemUpgrade
{
public:
    /**
     * @brief Constructs a SewageSystemLevelTwoUpgrade object.
     *
     * Initializes the upgrade by enhancing the specified SewageSystem with a level two upgrade.
     *
     * @param sewage Pointer to the original SewageSystem to be upgraded.
     */
    SewageSystemLevelTwoUpgrade(SewageSystem *sewage);

    /**
     * @brief Copy constructor for SewageSystemLevelTwoUpgrade.
     *
     * Creates a new SewageSystemLevelTwoUpgrade object by copying the attributes of an existing
     * SewageSystemLevelTwoUpgrade object.
     * 
     * @param sSLTU Pointer to the existing SewageSystemLevelTwoUpgrade to be copied.
     */
    SewageSystemLevelTwoUpgrade(SewageSystemLevelTwoUpgrade *sSLTU);

    /**
     * @brief Destructor for SewageSystemLevelTwoUpgrade.
     *
     * Cleans up any resources associated with the upgrade.
     */
    ~SewageSystemLevelTwoUpgrade();

    /**
     * @brief Updates the state of the upgraded sewage system.
     *
     * Implements specific behavior for the sewage system after applying the level two upgrade.
     */
    void update() override;

    /**
     * @brief Clones the current SewageSystemLevelTwoUpgrade object.
     *
     * Creates a new instance of SewageSystemLevelTwoUpgrade with the same attributes as the current object.
     *
     * @return A pointer to the newly cloned SewageSystemLevelTwoUpgrade object.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade() override;

    /**
     * @brief Retrieves the upgraded sewage system's output.
     *
     * Returns the sewage system output after the level two upgrade.
     *
     * @return The updated output as an integer.
     */
    int getOutput() override;

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    Cost getCost() override;

    /**
     * @brief Gets the level of the sewage system upgrade.
     *
     * @return The level of the sewage system upgrade.
     */
    int getLevel() override;

private:
    const int UPGRADE = 4; ///< Multiplier applied to the original output for the level two upgrade.
};

#endif // SEWAGESYSTEMLEVELTWOUPGRADE_H
