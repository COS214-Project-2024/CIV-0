#ifndef UTILITY_H
#define UTILITY_H

#include "entities/base/Entity.h"
#include "entities/building/residential/ResidentialBuilding.h"

#include <string>

/**
 * @class Utility
 * @brief Represents a utility entity in the city builder, such as power plants or sewage systems.
 *
 * The Utility class is a specialized entity that has an output value, such as electricity or water.
 */
class Utility : public Entity
{
public:
    /**
     * @brief Constructs a Utility object with the specified parameters.
     * 
     * This constructor initializes a Utility instance with various attributes including output, 
     * resource consumption, effects, dimensions, and positioning.
     * 
     * @param ec         EntityConfig.
     * @param size    Size.
     * @param xPos      xPosition
     * @param yPos      yPosition
     */
    Utility(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Utility class.
     * 
     * Creates a deep copy of a Utility object by copying the attributes of an existing Utility object.
     * 
     * @param utility Pointer to the existing Utility object to be copied.
     */
    Utility(Utility* utility);

    /**
     * @brief Default constructor for the Utility class.
     * 
     * Creates a new Utility object without initializing any of it's values (naughty).
     */
    Utility();

    /**
     * @brief Destructor for the Utility object.
     */
    virtual ~Utility();

    /**
     * @brief Pure virtual function to update the utility's state.
     *
     * Implement this method to define how the utility behaves when its state is updated.
     */
    virtual void update() = 0;

    /**
     * @brief Retrieves the output of the utility.
     * 
     * @return The output value of the utility.
     */
    virtual int getOutput();

    /**
     * @brief Sets the output value of the utility.
     * 
     * @param output The new output value to be set.
     */
    void setOutput(int output);

    /**
     * @brief Pure virtual function to clone the utility.
     *
     * Implement this method to create a copy of the current utility instance.
     * 
     * @return A pointer to a new cloned Utility object.
     */
    virtual Entity* clone() = 0;

private:
    int output; ///< The output value of the utility (e.g., electricity or water produced).
};

#endif // UTILITY_H