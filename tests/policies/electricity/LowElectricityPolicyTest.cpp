#include "doctest.h"
#include "policies/electricity/LowElectricityPolicy.h"

/**
 * @brief Test LowElectricityPolicy reduces electricity usage correctly.
 */
TEST_CASE("Test LowElectricityPolicy") {
    LowElectricityPolicy lowPolicy;
    int initialUsage = 100;
    int expectedUsage = 75; // 75% of the initial usage
    
    CHECK(lowPolicy.calculateElectricityUsage(initialUsage) == expectedUsage);
}
