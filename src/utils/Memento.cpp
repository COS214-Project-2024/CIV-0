#include "Memento.h"

/**
 * @brief Constructor implementation for Memento.
 * 
 * @param name Name of the policy.
 * @param detail Detail of the policy.
 */
Memento::Memento(const std::string& name, const std::string& detail)
    : name(name), detail(detail) {}

/**
 * @brief Gets the name of the policy.
 * 
 * @return std::string Name of the policy.
 */
std::string Memento::getName() const {
    return name;
}

/**
 * @brief Gets the detail of the policy.
 * 
 * @return std::string Detail of the policy.
 */
std::string Memento::getDetail() const {
    return detail;
}

/**
 * @brief Sets the name of the policy.
 * 
 * @param name Name of the policy.
 */
void Memento::setName(const std::string& name) {
    this->name = name;
}

/**
 * @brief Sets the detail of the policy.
 * 
 * @param detail Detail of the policy.
 */
void Memento::setDetail(const std::string& detail) {
    this->detail = detail;
}