#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "NormalElectricityPolicy.h"

/**
 * @brief Test NormalElectricityPolicy does not change electricity usage.
 */
TEST_CASE("Test NormalElectricityPolicy") {
    NormalElectricityPolicy normalPolicy;
    int initialUsage = 100;
    
    CHECK(normalPolicy.calculateElectricityUsage(initialUsage) == initialUsage);
}