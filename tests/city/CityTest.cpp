#include "doctest.h"
#include "city/City.h"
#include "policies/water/LowWaterPolicy.h"
#include "policies/water/NormalWaterPolicy.h"
#include "policies/water/HighWaterPolicy.h"
#include "policies/electricity/LowElectricityPolicy.h"
#include "policies/electricity/NormalElectricityPolicy.h"
#include "policies/electricity/HighElectricityPolicy.h"

TEST_CASE("CityTest test") {
    // Add your test cases here
    CHECK(1 == 1);
}

/**
 * @brief Test for setting and getting LowWaterPolicy.
 *
 * This test verifies that when the water policy is set to `LOW_WATER_POLICY`,
 * the `City` class correctly assigns and retrieves a `LowWaterPolicy`.
 */
TEST_CASE("Set and Get LowWaterPolicy in City") {
    City* city = City::instance();
    city->setWaterPolicy(PolicyType::LOW_WATER_POLICY);

    WaterPolicy* policy = city->getWaterPolicy();
    CHECK(dynamic_cast<LowWaterPolicy*>(policy) != nullptr); // Ensure policy is LowWaterPolicy
}

/**
 * @brief Test for setting and getting NormalWaterPolicy.
 *
 * This test verifies that when the water policy is set to `NORMAL_WATER_POLICY`,
 * the `City` class correctly assigns and retrieves a `NormalWaterPolicy`.
 */
TEST_CASE("Set and Get NormalWaterPolicy in City") {
    City* city = City::instance();
    city->setWaterPolicy(PolicyType::NORMAL_WATER_POLICY);

    WaterPolicy* policy = city->getWaterPolicy();
    CHECK(dynamic_cast<NormalWaterPolicy*>(policy) != nullptr); // Ensure policy is NormalWaterPolicy
}

/**
 * @brief Test for setting and getting HighWaterPolicy.
 *
 * This test verifies that when the water policy is set to `HIGH_WATER_POLICY`,
 * the `City` class correctly assigns and retrieves a `HighWaterPolicy`.
 */
TEST_CASE("Set and Get HighWaterPolicy in City") {
    City* city = City::instance();
    city->setWaterPolicy(PolicyType::HIGH_WATER_POLICY);

    WaterPolicy* policy = city->getWaterPolicy();
    CHECK(dynamic_cast<HighWaterPolicy*>(policy) != nullptr); // Ensure policy is HighWaterPolicy
}

/**
 * @brief Test for setting and getting LowElectricityPolicy.
 *
 * This test verifies that when the electricity policy is set to `LOW_ELECTRICITY_POLICY`,
 * the `City` class correctly assigns and retrieves a `LowElectricityPolicy`.
 */
TEST_CASE("Set and Get LowElectricityPolicy in City") {
    City* city = City::instance();
    city->setElectricityPolicy(PolicyType::LOW_ELECTRICITY_POLICY);

    ElectricityPolicy* policy = city->getElectricityPolicy();
    CHECK(dynamic_cast<LowElectricityPolicy*>(policy) != nullptr); // Ensure policy is LowElectricityPolicy
}

/**
 * @brief Test for setting and getting NormalElectricityPolicy.
 *
 * This test verifies that when the electricity policy is set to `NORMAL_ELECTRICITY_POLICY`,
 * the `City` class correctly assigns and retrieves a `NormalElectricityPolicy`.
 */
TEST_CASE("Set and Get NormalElectricityPolicy in City") {
    City* city = City::instance();
    city->setElectricityPolicy(PolicyType::NORMAL_ELECTRICITY_POLICY);

    ElectricityPolicy* policy = city->getElectricityPolicy();
    CHECK(dynamic_cast<NormalElectricityPolicy*>(policy) != nullptr); // Ensure policy is NormalElectricityPolicy
}

/**
 * @brief Test for setting and getting HighElectricityPolicy.
 *
 * This test verifies that when the electricity policy is set to `HIGH_ELECTRICITY_POLICY`,
 * the `City` class correctly assigns and retrieves a `HighElectricityPolicy`.
 */
TEST_CASE("Set and Get HighElectricityPolicy in City") {
    City* city = City::instance();
    city->setElectricityPolicy(PolicyType::HIGH_ELECTRICITY_POLICY);

    ElectricityPolicy* policy = city->getElectricityPolicy();
    CHECK(dynamic_cast<HighElectricityPolicy*>(policy) != nullptr); // Ensure policy is HighElectricityPolicy
}
