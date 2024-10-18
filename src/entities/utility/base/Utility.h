#ifndef UTILITY_H
#define UTILITY_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"

#include <string>

/**
 * @class Utility
 * @brief Represents a utility entity in the city builder, such as power plants or sewage systems.
 *
 * The Utility class is a specialized entity that has an output value, such as electricity or water.
 */
class Utility : public Entity, public Subject
{
public:
    /**
     * @brief Constructs a Utility object.
     *
     * @param xPos The X-coordinate of the utility on the grid.
     * @param yPos The Y-coordinate of the utility on the grid.
     * @param output The output value (e.g., electricity or water produced).
     * @param size The size of the utility (SMALL, MEDIUM, LARGE).
     * @param symbol A string representing the symbol used to depict the utility in the city grid.
     */
    Utility(int output, int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);

    /**
     * @brief Copy constructor for the Utility class.
     * 
     * Creates a deep copy of a Utility object by copying the attributes of an existing Utility object.
     * 
     * @param utility Pointer to the existing Utility object to be copied.
     */
    Utility(Utility* utility);

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
     * This method updates the output of the utility, which can represent resources such as electricity or water.
     * 
     * @param output The new output value to be set.
     */
    virtual void setOutput(int output);

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