#include "LowElectricityPolicy.h"

/**
 * @brief Implementation of LowElectricityPolicy to reduce electricity usage by 25%.
 * 
 * @param electricityUsage Initial electricity usage.
 * @return int Reduced electricity usage.
 */
int LowElectricityPolicy::calculateElectricityUsage(int electricityUsage) {
    return static_cast<int>(electricityUsage * 0.75);
}