#include "NormalWaterPolicy.h"

/**
 * @brief Implementation of NormalWaterPolicy to keep water usage unchanged.
 * 
 * @param waterUsage Initial water usage.
 * @return int Unchanged water usage.
 */
int NormalWaterPolicy::calculateWaterUsage(int waterUsage) {
    return waterUsage;
}