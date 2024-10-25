#include "doctest.h"
#include "policies/electricity/NormalElectricityPolicy.h"

/**
 * @brief Test NormalElectricityPolicy does not change electricity usage.
 */
TEST_CASE("Test NormalElectricityPolicy") {
    NormalElectricityPolicy normalPolicy;
    int initialUsage = 100;
    
    CHECK(normalPolicy.calculateElectricityUsage(initialUsage) == initialUsage);
}