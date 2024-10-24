#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "HighWaterPolicy.h"

/**
 * @brief Test HighWaterPolicy increases water usage correctly.
 */
TEST_CASE("Test HighWaterPolicy") {
    HighWaterPolicy highPolicy;
    int initialUsage = 100;
    int expectedUsage = 120; // 120% of the initial usage
    
    CHECK(highPolicy.calculateWaterUsage(initialUsage) == expectedUsage);
}