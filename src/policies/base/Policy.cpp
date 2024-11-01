#include "Policy.h"

/**
 * @brief Constructor for Policy.
 * 
 * @param name Name of the policy.
 * @param detail Detail of the policy.
 */
Policy::Policy(const std::string& name, const std::string& detail)
    : name(name), detail(detail) {}

/**
 * @brief Creates a memento to store the current state of the policy.
 * 
 * This method captures the current state (name and detail) of the policy
 * and returns a Memento object containing this state.
 * 
 * @return Memento* A pointer to a new Memento object containing the current state.
 */
Memento* Policy::createMemento() const {
    return new Memento(name, detail);
}

/**
 * @brief Restores the policy state from a provided memento.
 * 
 * This method sets the policy's name and detail based on the memento's state.
 * 
 * @param memento A pointer to the Memento object containing the saved state.
 */
void Policy::setMemento(const Memento* memento) {
    if (memento) {
        name = memento->getName();
        detail = memento->getDetail();
    }
}

/**
 * @brief Gets the name of the policy.
 * 
 * @return std::string Name of the policy.
 */
std::string Policy::getName() const {
    return name;
}

/**
 * @brief Gets the detail of the policy.
 * 
 * @return std::string Detail of the policy.
 */
std::string Policy::getDetail() const {
    return detail;
}
