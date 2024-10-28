#include "doctest.h"
#include "utils/EntityConfig.h"

TEST_CASE("EntityConfigTest test")
{
    SUBCASE("Default constructor")
    {
        EntityConfig defaultConfig;
        CHECK(defaultConfig.cost.moneyCost == 0);
        CHECK(defaultConfig.electricityConsumption == 0.0f);
        CHECK(defaultConfig.waterConsumption == 0.0f);
        CHECK(defaultConfig.symbol == "");
        CHECK(defaultConfig.effectRadius == 0);
        CHECK(defaultConfig.localEffectStrength == 0);
        CHECK(defaultConfig.globalEffectStrength == 0);
        CHECK(defaultConfig.width == 1);
        CHECK(defaultConfig.height == 1);
        CHECK(defaultConfig.revenue == 0);
    }

    SUBCASE("Parameterized constructor")
    {
        Cost cost(100, 50, 20, 10);
        EntityConfig customConfig(cost, 5.0f, 3.0f, "H", 10, 5, 2, 4, 4, 2000);

        CHECK(customConfig.cost.moneyCost == 100);
        CHECK(customConfig.electricityConsumption == 5.0f);
        CHECK(customConfig.waterConsumption == 3.0f);
        CHECK(customConfig.symbol == "H");
        CHECK(customConfig.effectRadius == 10);
        CHECK(customConfig.localEffectStrength == 5);
        CHECK(customConfig.globalEffectStrength == 2);
        CHECK(customConfig.width == 4);
        CHECK(customConfig.height == 4);
        CHECK(customConfig.revenue == 2000);
    }
}
