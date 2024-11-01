#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <vector>

/**
 * @brief Class representing a Caretaker for managing Memento objects.
 * 
 * Stores and retrieves the saved states of policies.
 */
class Caretaker {
private:
    std::vector<Memento*> pastStrategies; ///< Stores the history of mementos (Memento pointers)

public:
    /**
     * @brief Sets a new Memento by adding it to the stored history.
     * 
     * @param memento Pointer to the Memento to be added and set as the most recent.
     */
    void setMemento(Memento* memento);

    /**
     * @brief Retrieves a pointer to the most recent Memento from the stored history.
     * 
     * @return Memento* Pointer to the most recent Memento, or nullptr if no Memento exists.
     */
    Memento* getMemento() const;

    /**
     * @brief Destructor to free the memory allocated for mementos.
     */
    ~Caretaker();

    /**
     * @brief Retrieves all past policies stored in the caretaker.
     * 
     * @return Vector of pointers to Memento objects representing past policies.
     */
    std::vector<Memento*> getPastPolicies() const;
};

#endif