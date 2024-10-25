#include "doctest.h"
#include "policies/electricity/HighElectricityPolicy.h"

/**
 * @brief Test HighElectricityPolicy increases electricity usage correctly.
 */
TEST_CASE("Test HighElectricityPolicy") {
    HighElectricityPolicy highPolicy;
    int initialUsage = 100;
    int expectedUsage = 125; // 125% of the initial usage
    
    CHECK(highPolicy.calculateElectricityUsage(initialUsage) == expectedUsage);
}