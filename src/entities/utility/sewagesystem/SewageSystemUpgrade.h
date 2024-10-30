#ifndef SEWAGESYSTEMUPGRADE_H
#define SEWAGESYSTEMUPGRADE_H

#include "entities/utility/sewagesystem/SewageSystem.h"

/**
 * @class SewageSystemUpgrade
 * @brief Represents an upgrade to a SewageSystem entity in the city builder simulation.
 *
 * The SewageSystemUpgrade class extends the functionality of a SewageSystem, enhancing its capabilities
 * and acting as a wrapper around the existing SewageSystem object.
 */
class SewageSystemUpgrade : public SewageSystem
{
public:
    /**
     * @brief Constructs a SewageSystemUpgrade object based on an existing SewageSystem.
     * 
     * Initializes the upgrade with a reference to an existing SewageSystem, enhancing its features.
     * 
     * @param sewage Pointer to the SewageSystem being upgraded.
     */
    SewageSystemUpgrade(SewageSystem* sewage);

    /**
     * @brief Copy constructor for the SewageSystemUpgrade class.
     * 
     * Creates a new SewageSystemUpgrade object by copying the attributes of an existing SewageSystemUpgrade.
     * 
     * @param sewageSystemUpgrade Pointer to the existing SewageSystemUpgrade object to be copied.
     */
    SewageSystemUpgrade(SewageSystemUpgrade* sewageSystemUpgrade);

    /**
     * @brief Destructor for the SewageSystemUpgrade object.
     */
    virtual ~SewageSystemUpgrade();

    /**
     * @brief Pure virtual function to update the upgraded sewage system.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function to clone the upgraded sewage system.
     * 
     * @return A pointer to a new cloned SewageSystemUpgrade object.
     */
    virtual Entity* clone() = 0;

    virtual Entity* upgrade() = 0;

    /**
     * @brief Retrieves the output of the upgraded sewage system.
     * 
     * @return The output value as an integer.
     */
    virtual int getOutput() = 0;

    virtual Cost getCost() = 0;

protected:
    SewageSystem* sewageSystem; ///< Pointer to the original SewageSystem that is being upgraded.
};

#endif // SEWAGESYSTEMUPGRADE_H
