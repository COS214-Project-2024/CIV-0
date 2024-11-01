#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "entities/utility/base/Utility.h"

class WasteManagementLevelOneUpgrade;

/**
 * @class WasteManagement
 * @brief Represents a waste management facility in the city builder simulation.
 *
 * The WasteManagement class is a type of Utility that handles waste disposal for the city.
 */
class WasteManagement : public Utility
{
public:
    /**
     * @brief Constructs a WasteManagement object with specified attributes.
     *
     * Initializes a WasteManagement facility with detailed parameters, including utility consumption, effects, and dimensions.
     *
     * @param ec        EntityConfig.
     * @param size      Size.
     * @param xPos      xPosition
     * @param yPos      yPosition
     */
    WasteManagement(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the WasteManagement class.
     *
     * Creates a new WasteManagement object by copying the attributes of an existing WasteManagement.
     *
     * @param waste Pointer to the existing WasteManagement object to be copied.
     */
    WasteManagement(WasteManagement *waste);

    /**
     * @brief Default constructor for the WasteManagement class.
     *
     * Creates a new WasteManagement object without initializing any of it's values (naughty).
     */
    WasteManagement();

    /**
     * @brief Destructor for the WasteManagement object.
     */
    virtual ~WasteManagement();

    /**
     * @brief Updates the state of the waste management facility.
     *
     * Defines the specific behavior of the WasteManagement facility when it is updated in the simulation.
     */
    void update() override;

    /**
     * @brief Clones the current WasteManagement object.
     *
     * Creates and returns a copy of the current WasteManagement instance.
     *
     * @return A pointer to the newly cloned WasteManagement object.
     */
    Entity *clone() override;

    /**
     * @brief Upgrades the current utility to the next level.
     * @return A pointer to the upgraded utility instance, or nullptr if already at maximum level.
     */
    Entity *upgrade() override;
};

#endif // WASTEMANAGEMENT_H
