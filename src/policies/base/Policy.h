#ifndef POLICY_H
#define POLICY_H

#include "utils/Memento.h"
#include <string>

/**
 * @brief Class representing a Policy.
 * 
 * Can create a Memento to save its state and restore from it.
 */
class Policy {
private:
    std::string name;   ///< Name of the policy
    std::string detail; ///< Detail of the policy

public:
    /**
     * @brief Constructor for Policy.
     * 
     * @param name Name of the policy.
     * @param detail Detail of the policy.
     */
    Policy(const std::string& name, const std::string& detail);

    /**
     * @brief Creates a memento to store the current state of the policy.
     * 
     * @return Memento* Pointer to a new Memento object representing the current state.
     */
    Memento* createMemento() const;

    /**
     * @brief Restores the state of the policy from a Memento.
     * 
     * @param memento The memento to restore from.
     */
    void setMemento(const Memento& memento);

    /**
     * @brief Gets the name of the policy.
     * 
     * @return std::string Name of the policy.
     */
    std::string getName() const;

    /**
     * @brief Gets the detail of the policy.
     * 
     * @return std::string Detail of the policy.
     */
    std::string getDetail() const;
};

#endif
