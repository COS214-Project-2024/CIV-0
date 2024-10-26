#ifndef LOWELECTRICITYPOLICY_H
#define LOWELECTRICITYPOLICY_H

#include "ElectricityPolicy.h"

/**
 * @brief Concrete strategy for low electricity policy.
 * 
 * Reduces electricity usage by applying a low usage factor.
 */
class LowElectricityPolicy : public ElectricityPolicy {
public:
    /**
     * @brief Overrides calculateElectricityUsage to reduce electricity usage.
     * 
     * @param electricityUsage Initial electricity usage.
     * @return int Reduced electricity usage (e.g., 75% of the original).
     */
    int calculateElectricityUsage(int electricityUsage) override;
};

#endif
