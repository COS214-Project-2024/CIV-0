#ifndef BUILT_H
#define BUILT_H

#include "State.h"

/**
 * @class Built
 * @brief Represents the built state of an entity.
 *
 * The Built class inherits from the State class and represents the state of
 * an entity after it has been constructed. It provides methods for updating
 * and initializing the state.
 */
class Built : public State
{
public:
    /**
     * @brief Constructs a Built state with the specified build time.
     * @param buildTime The time taken to build the entity.
     */
    Built(int buildTime);
    
    /**
     * @brief Destructor for the Built state.
     */
    ~Built();
    
    /**
     * @brief Updates the current state.
     * @return A pointer to the updated state (remains the same in the built state).
     */
    State* update();
    
    /**
     * @brief Initializes the current state.
     * @return A pointer to the initialized state (remains the same in the built state).
     */
    State* initialize();
};

#endif // BUILT_H
