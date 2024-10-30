#include "doctest.h"
#include "utils/Cost.h"

TEST_SUITE("CostTest test")
{
    TEST_CASE("Default constructor")
    {
        Cost defaultCost;
        CHECK(defaultCost.moneyCost == 0);
        CHECK(defaultCost.woodCost == 0);
        CHECK(defaultCost.stoneCost == 0);
        CHECK(defaultCost.concreteCost == 0);
    }

    TEST_CASE("Parameterized constructor")
    {
        Cost customCost(100, 50, 20, 10);
        CHECK(customCost.moneyCost == 100);
        CHECK(customCost.woodCost == 50);
        CHECK(customCost.stoneCost == 20);
        CHECK(customCost.concreteCost == 10);
    }

    TEST_CASE("Modifying Cost values")
    {
        Cost modifiableCost(200, 80, 40, 30);
        modifiableCost.moneyCost = 300;
        CHECK(modifiableCost.moneyCost == 300);
        modifiableCost.woodCost = 100;
        CHECK(modifiableCost.woodCost == 100);
    }

    TEST_CASE("Equal-to operator test") {
        Cost cost1(100, 200, 300, 400);
        Cost cost2(100, 200, 300, 400);
        Cost cost3(50, 200, 300, 400);
        Cost cost4(100, 100, 300, 400);
        Cost cost5(100, 200, 150, 400);
        Cost cost6(100, 200, 300, 50);

        SUBCASE("Identical costs should be equal") {
            CHECK(cost1 == cost2);
        }

        SUBCASE("Costs with different moneyCost should not be equal") {
            CHECK_FALSE(cost1 == cost3);
        }

        SUBCASE("Costs with different woodCost should not be equal") {
            CHECK_FALSE(cost1 == cost4);
        }

        SUBCASE("Costs with different stoneCost should not be equal") {
            CHECK_FALSE(cost1 == cost5);
        }

        SUBCASE("Costs with different concreteCost should not be equal") {
            CHECK_FALSE(cost1 == cost6);
        }
    }
}