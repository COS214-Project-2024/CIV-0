#ifndef LOWWATERPOLICY_H
#define LOWWATERPOLICY_H

#include "WaterPolicy.h"

/**
 * @brief Concrete strategy for low water policy.
 * 
 * Reduces water usage by applying a low usage factor.
 */
class LowWaterPolicy : public WaterPolicy {
public:
    /**
     * @brief Overrides calculateWaterUsage to reduce water usage.
     * 
     * @param waterUsage Initial water usage.
     * @return int Reduced water usage (e.g., 80% of the original).
     */
    int calculateWaterUsage(int waterUsage) override;
    /**
     * @brief Constructor for LowWaterPolicy.
     * Initializes the policy with specific name and detail.
     */
    LowWaterPolicy() : WaterPolicy("LowWaterPolicy", "This policy minimises water usage.") {}
};

#endif
