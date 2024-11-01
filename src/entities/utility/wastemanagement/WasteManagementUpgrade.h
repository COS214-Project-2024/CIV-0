#ifndef WASTEMANAGEMENTUPGRADE_H
#define WASTEMANAGEMENTUPGRADE_H

#include "entities/utility/wastemanagement/WasteManagement.h"

/**
 * @class WasteManagementUpgrade
 * @brief Represents an upgrade to a WasteManagement entity in the city builder simulation.
 *
 * The WasteManagementUpgrade class extends the functionality of a WasteManagement, enhancing its capabilities
 * and acting as a wrapper around the existing WasteManagement object.
 */
class WasteManagementUpgrade : public WasteManagement
{
public:
    /**
     * @brief Constructs a WasteManagementUpgrade object based on an existing WasteManagement.
     * 
     * Initializes the upgrade with a reference to an existing WasteManagement, enhancing its features.
     * 
     * @param waste Pointer to the WasteManagement being upgraded.
     */
    WasteManagementUpgrade(WasteManagement* waste);

    /**
     * @brief Copy constructor for the WasteManagementUpgrade class.
     * 
     * Creates a new WasteManagementUpgrade object by copying the attributes of an existing WasteManagementUpgrade.
     * 
     * @param wMU Pointer to the existing WasteManagementUpgrade object to be copied.
     */
    WasteManagementUpgrade(WasteManagementUpgrade* wMU);

    /**
     * @brief Destructor for the WasteManagementUpgrade object.
     */
    virtual ~WasteManagementUpgrade();

    /**
     * @brief Pure virtual function to update the upgraded waste management system.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function to clone the upgraded waste management system.
     * 
     * @return A pointer to a new cloned WasteManagementUpgrade object.
     */
    virtual Entity* clone() = 0;

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    virtual Entity* upgrade() = 0;

    /**
     * @brief Retrieves the output of the upgraded waste management system.
     * 
     * @return The output value as an integer.
     */
    virtual int getOutput() = 0;

    /**
     * @brief Retrieves the cost of the utility or its upgraded version.
     * @return A Cost object representing the monetary and material costs.
     */
    virtual Cost getCost() = 0;

protected:
    WasteManagement* wasteManagement; ///< Pointer to the original WasteManagement that is being upgraded.
};

#endif // WASTEMANAGEMENTUPGRADE_H
