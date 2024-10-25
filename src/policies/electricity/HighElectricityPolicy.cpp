#include "HighElectricityPolicy.h"

/**
 * @brief Implementation of HighElectricityPolicy to increase electricity usage by 25%.
 * 
 * @param electricityUsage Initial electricity usage.
 * @return int Increased electricity usage.
 */
int HighElectricityPolicy::calculateElectricityUsage(int electricityUsage) {
    return static_cast<int>(electricityUsage * 1.25);
}