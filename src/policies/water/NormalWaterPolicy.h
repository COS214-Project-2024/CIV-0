#ifndef NORMALWATERPOLICY_H
#define NORMALWATERPOLICY_H

#include "WaterPolicy.h"

/**
 * @brief Concrete strategy for normal water policy.
 * 
 * Keeps the water usage unchanged.
 */
class NormalWaterPolicy : public WaterPolicy {
public:
    /**
     * @brief Overrides calculateWaterUsage to keep water usage unchanged.
     * 
     * @param waterUsage Initial water usage.
     * @return int The same water usage as provided.
     */
    int calculateWaterUsage(int waterUsage) override;
    /**
     * @brief Constructor for NormalWaterPolicy.
     * Initializes the policy with specific name and detail.
     */
    NormalWaterPolicy() : WaterPolicy("NormalWaterPolicy", "This policy maintains average water usage.") {}
};

#endif