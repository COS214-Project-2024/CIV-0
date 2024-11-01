#ifndef HIGHELECTRICITYPOLICY_H
#define HIGHELECTRICITYPOLICY_H

#include "ElectricityPolicy.h"

/**
 * @brief Concrete strategy for high electricity policy.
 * 
 * Increases electricity usage by applying a high usage factor.
 */
class HighElectricityPolicy : public ElectricityPolicy {
public:
    /**
     * @brief Overrides calculateElectricityUsage to increase electricity usage.
     * 
     * @param electricityUsage Initial electricity usage.
     * @return int Increased electricity usage (e.g., 125% of the original).
     */
    int calculateElectricityUsage(int electricityUsage) override;

    /**
     * @brief Constructor for HighElectricityPolicy.
     * Initializes the policy with specific name and detail.
     */
    HighElectricityPolicy() : ElectricityPolicy("HighElectricityPolicy", "This policy allows for high electricity usage.") {}
};

#endif
