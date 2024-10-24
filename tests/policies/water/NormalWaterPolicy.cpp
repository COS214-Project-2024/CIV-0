#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "NormalWaterPolicy.h"

/**
 * @brief Test NormalWaterPolicy does not change water usage.
 */
TEST_CASE("Test NormalWaterPolicy") {
    NormalWaterPolicy normalPolicy;
    int initialUsage = 100;
    
    CHECK(normalPolicy.calculateWaterUsage(initialUsage) == initialUsage);
}