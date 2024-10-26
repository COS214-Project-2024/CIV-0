#include "doctest.h"
#include "policies/water/NormalWaterPolicy.h"

/**
 * @brief Test NormalWaterPolicy does not change water usage.
 */
TEST_CASE("Test NormalWaterPolicy") {
    NormalWaterPolicy normalPolicy;
    int initialUsage = 100;
    
    CHECK(normalPolicy.calculateWaterUsage(initialUsage) == initialUsage);
}