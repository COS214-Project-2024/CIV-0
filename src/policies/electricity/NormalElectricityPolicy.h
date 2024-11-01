#ifndef NORMALELECTRICITYPOLICY_H
#define NORMALELECTRICITYPOLICY_H

#include "ElectricityPolicy.h"

/**
 * @brief Concrete strategy for normal electricity policy.
 * 
 * Keeps electricity usage unchanged.
 */
class NormalElectricityPolicy : public ElectricityPolicy {
public:
    /**
     * @brief Overrides calculateElectricityUsage to keep electricity usage unchanged.
     * 
     * @param electricityUsage Initial electricity usage.
     * @return int Unchanged electricity usage.
     */
    int calculateElectricityUsage(int electricityUsage) override;

    /**
     * @brief Constructor for NormalElectricityPolicy.
     * Initializes the policy with specific name and detail.
     */
    NormalElectricityPolicy() : ElectricityPolicy("NormalElectricityPolicy", "This policy maintains average electricity usage.") {}
};

#endif