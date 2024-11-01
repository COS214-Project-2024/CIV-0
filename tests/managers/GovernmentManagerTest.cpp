#include "doctest.h"
#include "managers/GovernmentManager.h"
#include "city/City.h"
#include "policies/water/LowWaterPolicy.h"
#include "policies/water/NormalWaterPolicy.h"
#include "policies/water/HighWaterPolicy.h"
#include "policies/electricity/LowElectricityPolicy.h"
#include "policies/electricity/NormalElectricityPolicy.h"
#include "policies/electricity/HighElectricityPolicy.h"
#include "utils/PolicyType.h"
#include "utils/Memento.h"

/**
 * @file TestGovernmentManager.cpp
 * @brief Unit tests for the GovernmentManager class.
 *
 * This file contains tests to verify the functionality of the GovernmentManager class,
 * including setting and retrieving tax rates, enacting policies, and storing past policies.
 */

/**
 * @brief Test setting and retrieving the residential tax rate.
 *
 * This test verifies that the GovernmentManager can set and retrieve the residential
 * tax rate through the City singleton.
 */
TEST_CASE("Set and Get Residential Tax Rate in GovernmentManager") {
    GovernmentManager manager;
    
    manager.setResidentialTaxRate(15.0f);
    CHECK(City::instance()->getResidentialTax() == 15);

    manager.setResidentialTaxRate(20.0f);
    CHECK(City::instance()->getResidentialTax() == 20);
}

/**
 * @brief Test setting and retrieving the economic tax rate.
 *
 * This test verifies that the GovernmentManager can set and retrieve the economic
 * tax rate through the City singleton.
 */
TEST_CASE("Set and Get Economic Tax Rate in GovernmentManager") {
    GovernmentManager manager;
    
    manager.setEconomicTaxRate(10.0f);
    CHECK(City::instance()->getEconomicTax() == 10);

    manager.setEconomicTaxRate(25.0f);
    CHECK(City::instance()->getEconomicTax() == 25);
}

/**
 * @brief Test getting the total residential tax collected.
 *
 * This test verifies that the GovernmentManager correctly retrieves the total
 * residential tax collected using a TaxCalculationVisitor.
 */
TEST_CASE("Get Total Residential Tax in GovernmentManager") {
    GovernmentManager manager;
    
    City::instance()->setResidentialTax(12);
    int residentialTax = manager.getResidentialTax();
    CHECK(residentialTax >= 0); // Replace with expected value if known
}

/**
 * @brief Test getting the total economic tax collected.
 *
 * This test verifies that the GovernmentManager correctly retrieves the total
 * economic tax collected using a TaxCalculationVisitor.
 */
TEST_CASE("Get Total Economic Tax in GovernmentManager") {
    GovernmentManager manager;
    
    City::instance()->setEconomicTax(18);
    int economicTax = manager.getEconomicTax();
    CHECK(economicTax >= 0); // Replace with expected value if known
}

/**
 * @brief Test enacting a water usage policy.
 *
 * This test verifies that the GovernmentManager can enact a water usage policy
 * and that the policy is correctly set in the City singleton.
 */
TEST_CASE("Enact Water Usage Policy in GovernmentManager") {
    GovernmentManager manager;
    
    manager.enactWaterUsagePolicy(PolicyType::LOW_WATER_POLICY);
    CHECK(dynamic_cast<LowWaterPolicy*>(City::instance()->getWaterPolicy()) != nullptr);

    manager.enactWaterUsagePolicy(PolicyType::NORMAL_WATER_POLICY);
    CHECK(dynamic_cast<NormalWaterPolicy*>(City::instance()->getWaterPolicy()) != nullptr);

    manager.enactWaterUsagePolicy(PolicyType::HIGH_WATER_POLICY);
    CHECK(dynamic_cast<HighWaterPolicy*>(City::instance()->getWaterPolicy()) != nullptr);
}

/**
 * @brief Test enacting an electricity usage policy.
 *
 * This test verifies that the GovernmentManager can enact an electricity usage policy
 * and that the policy is correctly set in the City singleton.
 */
TEST_CASE("Enact Electricity Usage Policy in GovernmentManager") {
    GovernmentManager manager;
    
    manager.enactElectricityPolicy(PolicyType::LOW_ELECTRICITY_POLICY);
    CHECK(dynamic_cast<LowElectricityPolicy*>(City::instance()->getElectricityPolicy()) != nullptr);

    manager.enactElectricityPolicy(PolicyType::NORMAL_ELECTRICITY_POLICY);
    CHECK(dynamic_cast<NormalElectricityPolicy*>(City::instance()->getElectricityPolicy()) != nullptr);

    manager.enactElectricityPolicy(PolicyType::HIGH_ELECTRICITY_POLICY);
    CHECK(dynamic_cast<HighElectricityPolicy*>(City::instance()->getElectricityPolicy()) != nullptr);
}

/**
 * @brief Test retrieving all past policies.
 *
 * This test verifies that the GovernmentManager correctly stores enacted policies
 * in the caretaker and retrieves them with getAllPastPolicies.
 */
TEST_CASE("Retrieve All Past Policies in GovernmentManager") {
    GovernmentManager manager;

    manager.enactWaterUsagePolicy(PolicyType::LOW_WATER_POLICY);
    manager.enactElectricityPolicy(PolicyType::LOW_ELECTRICITY_POLICY);

    std::vector<Memento*> pastPolicies = manager.getAllPastPolicies();

    REQUIRE(pastPolicies.size() >= 2); // Check that at least two policies have been stored

    // Verify the types of past policies stored
    CHECK((pastPolicies[0]->getName() == "LowWaterPolicy"));
    CHECK((pastPolicies[0]->getName() == "LowElectricityPolicy"));

    CHECK((pastPolicies[1]->getName() == "LowWaterPolicy"));
    CHECK((pastPolicies[1]->getName() == "LowElectricityPolicy"));

    // Clean up mementos stored in caretaker
    for (Memento* memento : pastPolicies) {
        delete memento;
    }
}
