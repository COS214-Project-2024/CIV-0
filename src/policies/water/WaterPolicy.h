#ifndef WATERPOLICY_H
#define WATERPOLICY_H

#include "policies/base/Policy.h"

/**
 * @brief Abstract class for WaterPolicy.
 * 
 * Defines the interface for calculating water usage based on different policy strategies.
 */
class WaterPolicy : public Policy {
public:
    /**
     * @brief Constructor for WaterPolicy.
     * 
     * @param name Name of the policy.
     * @param detail Details describing the policy.
     */
    WaterPolicy(const std::string& name, const std::string& detail) : Policy(name, detail) {}
    /**
     * @brief Pure virtual function to calculate water usage.
     * 
     * @param waterUsage Initial water usage.
     * @return int Modified water usage based on policy.
     */
    virtual int calculateWaterUsage(int waterUsage) = 0;

    /**
     * @brief Virtual destructor for WaterPolicy.
     */
    virtual ~WaterPolicy() {}
};

#endif
