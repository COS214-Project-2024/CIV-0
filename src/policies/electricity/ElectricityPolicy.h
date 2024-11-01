#ifndef ELECTRICITYPOLICY_H
#define ELECTRICITYPOLICY_H

#include "policies/base/Policy.h"

/**
 * @brief Abstract class for ElectricityPolicy.
 * 
 * Defines the interface for calculating electricity usage based on different policy strategies.
 */
class ElectricityPolicy : public Policy {
public:
    /**
     * @brief Constructor for ElectricityPolicy.
     * 
     * @param name Name of the policy.
     * @param detail Details describing the policy.
     */
    ElectricityPolicy(const std::string& name, const std::string& detail) : Policy(name, detail) {}

    /**
     * @brief Pure virtual function to calculate electricity usage.
     * 
     * @param electricityUsage Initial electricity usage.
     * @return int Modified electricity usage based on policy.
     */
    virtual int calculateElectricityUsage(int electricityUsage) = 0;

    /**
     * @brief Virtual destructor for ElectricityPolicy.
     */
    virtual ~ElectricityPolicy() {}
};

#endif
