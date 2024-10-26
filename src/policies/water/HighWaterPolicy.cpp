#include "HighWaterPolicy.h"

/**
 * @brief Implementation of HighWaterPolicy to increase water usage by 20%.
 * 
 * @param waterUsage Initial water usage.
 * @return int Increased water usage.
 */
int HighWaterPolicy::calculateWaterUsage(int waterUsage) {
    return static_cast<int>(waterUsage * 1.2);
}