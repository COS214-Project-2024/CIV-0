#ifndef STATE_H
#define STATE_H

/**
 * @class State
 * @brief Abstract base class representing the state of an entity.
 *
 * The State class defines the interface for different states an entity can have.
 * Derived classes must implement the update and initialize methods to handle
 * state transitions.
 */
class State
{
private:
    int gameLoopCounter; ///< Counter for tracking game loops.
    int buildTime;      ///< Time required to complete the build.

public:
    /**
     * @brief Constructs a State with the specified build time.
     * @param buildTime The time required to build the entity.
     */
    State(int buildTime);
    
    /**
     * @brief Destructor for the State.
     */
    virtual ~State();
    
    /**
     * @brief Updates the current state.
     * @return A pointer to the next state after update.
     */
    virtual State* update() = 0;

    /**
     * @brief Initializes the current state.
     * @return A pointer to the next state after initialization.
     */
    virtual State* initialize() = 0;

    /**
     * @brief Gets the current game loop counter.
     * @return The current game loop counter.
     */
    int getGameLoopCounter();

    /**
     * @brief Gets the build time of the state.
     * @return The time required to complete the build.
     */
    int getBuildTime();

    /**
     * @brief Increments the game loop counter.
     */
    void incrementGameLoopCounter();
};

#endif // STATE_H
