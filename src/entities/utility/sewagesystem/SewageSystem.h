#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "entities/utility/base/Utility.h"

/**
 * @class SewageSystem
 * @brief Represents a sewage system in the city builder simulation.
 *
 * The SewageSystem class is a type of Utility that handles the city's sewage management.
 */
class SewageSystem : public Utility
{
public:
    /**
     * @brief Constructs a SewageSystem object with specified attributes.
     * 
     * Initializes a SewageSystem with detailed parameters, including utility consumption, effects, and dimensions.
     * 
     * @param ec         EntityConfig.
     * @param size    Size.
     * @param xPos      xPosition
     * @param yPos      yPosition
     */
    SewageSystem(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the SewageSystem class.
     * 
     * Creates a new SewageSystem object by copying the attributes of an existing SewageSystem.
     * 
     * @param sewageSystem Pointer to the existing SewageSystem object to be copied.
     */
    SewageSystem(SewageSystem* sewageSystem);

    /**
     * @brief Default constructor for the SewageSystem class.
     * 
     * Creates a new SewageSystem object without initializing any of it's values (naughty).
     */
    SewageSystem();

    /**
     * @brief Destructor for the SewageSystem object.
     */
    virtual ~SewageSystem();

    /**
     * @brief Updates the state of the sewage system.
     * 
     * Defines the specific behavior of the SewageSystem when it is updated in the simulation.
     */
    void update();

    /**
     * @brief Clones the current SewageSystem object.
     * 
     * Creates and returns a copy of the current SewageSystem instance.
     * 
     * @return A pointer to the newly cloned SewageSystem object.
     */
    Entity* clone();
};

#endif // SEWAGESYSTEM_H