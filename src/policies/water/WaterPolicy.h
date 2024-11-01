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
