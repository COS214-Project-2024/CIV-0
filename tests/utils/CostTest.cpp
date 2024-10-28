#include "doctest.h"
#include "utils/Cost.h"

TEST_CASE("CostTest test")
{
    SUBCASE("Default constructor")
    {
        Cost defaultCost;
        CHECK(defaultCost.moneyCost == 0);
        CHECK(defaultCost.woodCost == 0);
        CHECK(defaultCost.stoneCost == 0);
        CHECK(defaultCost.concreteCost == 0);
    }

    SUBCASE("Parameterized constructor")
    {
        Cost customCost(100, 50, 20, 10);
        CHECK(customCost.moneyCost == 100);
        CHECK(customCost.woodCost == 50);
        CHECK(customCost.stoneCost == 20);
        CHECK(customCost.concreteCost == 10);
    }

    SUBCASE("Modifying Cost values")
    {
        Cost modifiableCost(200, 80, 40, 30);
        modifiableCost.moneyCost = 300;
        CHECK(modifiableCost.moneyCost == 300);
        modifiableCost.woodCost = 100;
        CHECK(modifiableCost.woodCost == 100);
    }
}
