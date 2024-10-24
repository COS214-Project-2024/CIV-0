#include "NormalElectricityPolicy.h"

/**
 * @brief Implementation of NormalElectricityPolicy to keep electricity usage unchanged.
 * 
 * @param electricityUsage Initial electricity usage.
 * @return int Unchanged electricity usage.
 */
int NormalElectricityPolicy::calculateElectricityUsage(int electricityUsage) {
    return electricityUsage;
}
