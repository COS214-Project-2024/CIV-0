#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>

/**
 * @brief Class representing a Memento for saving and restoring the state of a Policy.
 * 
 */
class Memento {
private:
    std::string name;   ///< Name of the policy
    std::string detail; ///< Detail of the policy

public:
    /**
     * @brief Constructor for Memento.
     * 
     * @param name Name of the policy.
     * @param detail Detail of the policy.
     */
    Memento(const std::string& name, const std::string& detail);

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

    /**
     * @brief Sets the name of the policy.
     * 
     * @param name Name of the policy.
     */
    void setName(const std::string& name);

    /**
     * @brief Sets the detail of the policy.
     * 
     * @param detail Detail of the policy.
     */
    void setDetail(const std::string& detail);
};

#endif