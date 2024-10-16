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
     * @brief Destructor for the UnderConstruction state.
     */
    ~UnderConstruction();
    
    /**
     * @brief Updates the current construction state.
     * @return A pointer to the next state after the update, which may be a Built state.
     */
    State* update();
    
    /**
     * @brief Initializes the current construction state.
     * @return A pointer to the next state after initialization, which may be a Built state.
     */
    State* initialize();
};

#endif // UNDERCONSTRUCTION_H
