#ifndef HIGHWATERPOLICY_H
#define HIGHWATERPOLICY_H

#include "WaterPolicy.h"

/**
 * @brief Concrete strategy for high water policy.
 * 
 * Increases water usage by applying a high usage factor.
 */
class HighWaterPolicy : public WaterPolicy {
public:
    /**
     * @brief Overrides calculateWaterUsage to increase water usage.
     * 
     * @param waterUsage Initial water usage.
     * @return int Increased water usage (e.g., 120% of the original).
     */
    int calculateWaterUsage(int waterUsage) override;
    /**
     * @brief Constructor for HighWaterPolicy.
     * Initializes the policy with specific name and detail.
     */
    HighWaterPolicy() : WaterPolicy("HighWaterPolicy", "This policy allows for high water usage.") {}
};

#endif
