#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "State.h"

/**
 * @class UnderConstruction
 * @brief Represents the state of an entity that is currently under construction.
 *
 * The UnderConstruction class inherits from the State class and implements
 * the behavior for an entity that is in the process of being built.
 */
class UnderConstruction : public State
{
public:
    /**
     * @brief Constructs an UnderConstruction state with the specified build time.
     * @param buildTime The time required for the construction to complete.
     */
    UnderConstruction(int buildTime);
    
    /**
     * @brief Copy constructor for the UnderConstruction class.
     * 
     * Creates a new UnderConstruction state by copying the attributes of an existing UnderConstruction object.
     * 
     * @param underConstruction Pointer to the existing UnderConstruction object to be copied.
     */
    UnderConstruction(UnderConstruction* underConstruction);

    /**
     * @brief Destructor for the UnderConstruction state.
     */
    ~UnderConstruction();
    
    /**
     * @brief Updates the current construction state.
     * @return A pointer to the next state after the update, which may be a Built state.
     */
    State* update();
    
    /**
     * @brief Creates a deep copy of the UnderConstruction state.
     * 
     * This method returns a new UnderConstruction object that is a copy of the current instance.
     * This allows for proper polymorphic copying of State objects.
     * 
     * @return A pointer to a new UnderConstruction object that is a copy of this instance.
     */
    State* clone();
};

#endif // UNDERCONSTRUCTION_H
