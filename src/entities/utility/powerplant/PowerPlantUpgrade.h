#ifndef POWERPLANTUPGRADE_H
#define POWERPLANTUPGRADE_H

#include "entities/utility/powerplant/PowerPlant.h"

/**
 * @class PowerPlantUpgrade
 * @brief Represents an upgrade to a PowerPlant entity in the city builder simulation.
 *
 * The PowerPlantUpgrade class extends the functionality of a PowerPlant, enhancing its capabilities
 * and acting as a wrapper around the existing PowerPlant object.
 */
class PowerPlantUpgrade : public PowerPlant
{
public:
    /**
     * @brief Constructs a PowerPlantUpgrade object based on an existing PowerPlant.
     * 
     * Initializes the upgrade with a reference to an existing PowerPlant, enhancing its features.
     * 
     * @param powerPlant Pointer to the PowerPlant being upgraded.
     */
    PowerPlantUpgrade(PowerPlant* powerPlant);

    /**
     * @brief Copy constructor for the PowerPlantUpgrade class.
     * 
     * Creates a new PowerPlantUpgrade object by copying the attributes of an existing PowerPlantUpgrade.
     * 
     * @param powerPlantUpgrade Pointer to the existing PowerPlantUpgrade object to be copied.
     */
    PowerPlantUpgrade(PowerPlantUpgrade* powerPlantUpgrade);

    /**
     * @brief Destructor for the PowerPlantUpgrade object.
     */
    virtual ~PowerPlantUpgrade();

    /**
     * @brief Pure virtual function to update the upgraded power plant.
     * 
     * This method defines the specific behavior of the power plant after the upgrade when it is updated.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function to clone the upgraded power plant.
     * 
     * This method allows cloning of the upgraded power plant, creating a new instance with the same attributes.
     * 
     * @return A pointer to a new cloned PowerPlantUpgrade object.
     */
    virtual Entity* clone() = 0;

    /**
     * @brief Retrieves the output of the upgraded power plant.
     * 
     * @return The power output as an integer.
     */
    virtual int getOutput() = 0;

protected:
    PowerPlant* powerPlant; ///< Pointer to the original PowerPlant that is being upgraded.
};

#endif // POWERPLANTUPGRADE_H
