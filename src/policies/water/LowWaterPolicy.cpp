#include "LowWaterPolicy.h"

/**
 * @brief Implementation of LowWaterPolicy to reduce water usage by 20%.
 * 
 * @param waterUsage Initial water usage.
 * @return int Reduced water usage.
 */
int LowWaterPolicy::calculateWaterUsage(int waterUsage) {
    return static_cast<int>(waterUsage * 0.8);
}
