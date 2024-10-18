#ifndef SEWAGESYSTEMLEVELONEUPGRADE_H
#define SEWAGESYSTEMLEVELONEUPGRADE_H

#include "SewageSystemUpgrade.h"

/**
 * @class SewageSystemLevelOneUpgrade
 * @brief Represents the first level upgrade to a SewageSystem entity.
 *
 * The SewageSystemLevelOneUpgrade class enhances the base functionality of a SewageSystem by increasing
 * its output. This class is the first upgrade level in a series of potential sewage system improvements.
 */
class SewageSystemLevelOneUpgrade : public SewageSystemUpgrade
{
public:
    /**
     * @brief Constructs a SewageSystemLevelOneUpgrade object.
     * 
     * Initializes the upgrade by enhancing the specified SewageSystem with a level one upgrade.
     * 
     * @param sewageSystem Pointer to the original SewageSystem to be upgraded.
     */
    SewageSystemLevelOneUpgrade(SewageSystem* sewageSystem);

    /**
     * @brief Copy constructor for SewageSystemLevelOneUpgrade.
     * 
     * Creates a new SewageSystemLevelOneUpgrade object by copying the attributes of an existing
     * SewageSystemLevelOneUpgrade object.
     * 
     * @param sewageSystemLevelOneUpgrade Pointer to the existing SewageSystemLevelOneUpgrade to be copied.
     */
    SewageSystemLevelOneUpgrade(SewageSystemLevelOneUpgrade* sewageSystemLevelOneUpgrade);

    /**
     * @brief Destructor for SewageSystemLevelOneUpgrade.
     * 
     * Cleans up any resources associated with the upgrade.
     */
    ~SewageSystemLevelOneUpgrade();

    /**
     * @brief Updates the state of the upgraded sewage system.
     * 
     * Implements specific behavior for the sewage system after applying the level one upgrade.
     */
    void update();

    /**
     * @brief Clones the current SewageSystemLevelOneUpgrade object.
     * 
     * Creates a new instance of SewageSystemLevelOneUpgrade with the same attributes as the current object.
     * 
     * @return A pointer to the newly cloned SewageSystemLevelOneUpgrade object.
     */
    Entity* clone();

    /**
     * @brief Retrieves the upgraded sewage system's output.
     * 
     * Returns the output of the level one upgraded sewage system, which reflects a 1.5x enhancement.
     * 
     * @return The updated output as an integer.
     */
    int getOutput();

private:
    const int UPGRADE = 1.5; ///< Multiplier applied to the original sewage system output for the level one upgrade.
};

#endif // SEWAGESYSTEMLEVELONEUPGRADE_H
