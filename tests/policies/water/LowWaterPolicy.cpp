#include "doctest.h"
#include "policies/water/LowWaterPolicy.h"

/**
 * @brief Test LowWaterPolicy reduces water usage correctly.
 */
TEST_CASE("Test LowWaterPolicy") {
    LowWaterPolicy lowPolicy;
    int initialUsage = 100;
    int expectedUsage = 80; // 80% of the initial usage
    
    CHECK(lowPolicy.calculateWaterUsage(initialUsage) == expectedUsage);
}
