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
     * @brief Copy constructor for the Built class.
     * 
     * Creates a new Built state by copying the attributes of an existing Built object.
     * 
     * @param built Pointer to the existing Built object to be copied.
     */
    Built(Built* built);
    
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
     * @brief Creates a deep copy of the Built state.
     * 
     * This method returns a new Built object that is a copy of the current instance.
     * This allows for proper polymorphic copying of State objects.
     * 
     * @return A pointer to a new Built object that is a copy of this instance.
     */
    State* clone();
};

#endif // BUILT_H
