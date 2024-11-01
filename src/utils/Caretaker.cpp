#include "Caretaker.h"

/**
 * @brief Sets a new Memento by adding it to the stored history.
 * 
 * If a Memento is added, it becomes the most recent entry in the history.
 * 
 * @param memento Pointer to the new Memento to set.
 */
void Caretaker::setMemento(Memento* memento) {
    pastStrategies.push_back(memento);
}

/**
 * @brief Retrieves a pointer to the most recent Memento from the stored history.
 * 
 * @return Memento* Pointer to the most recent Memento, or nullptr if no Memento exists.
 */
Memento* Caretaker::getMemento() const {
    if (!pastStrategies.empty()) {
        return pastStrategies.back(); // Return the most recent Memento
    }
    return nullptr; // Return nullptr if no Memento is available
}

/**
 * @brief Destructor to free memory allocated for Memento pointers.
 */
Caretaker::~Caretaker() {
    for (Memento* memento : pastStrategies) {
        delete memento; // Free dynamically allocated Mementos
    }
}
/**
 * @brief Retrieves all past policies stored in the caretaker.
 * 
 * @return Vector of pointers to Memento objects representing past policies.
 */
std::vector<Memento*> Caretaker::getPastPolicies() const {
    return pastStrategies;
}
