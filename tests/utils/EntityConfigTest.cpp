#include "doctest.h"
#include "utils/EntityConfig.h"

TEST_CASE("EntityConfigTest")
{
    SUBCASE("Default constructor")
    {
        EntityConfig defaultConfig;

        // Default cost checks
        CHECK(defaultConfig.cost.moneyCost == 0);
        CHECK(defaultConfig.cost.woodCost == 0);
        CHECK(defaultConfig.cost.stoneCost == 0);
        CHECK(defaultConfig.cost.concreteCost == 0);

        // Default consumption and production checks
        CHECK(defaultConfig.electricityConsumption == 0);
        CHECK(defaultConfig.waterConsumption == 0);

        // Default properties

        CHECK(defaultConfig.symbol == "");
        CHECK(defaultConfig.effectRadius == 0);
        CHECK(defaultConfig.localEffectStrength == 0);
        CHECK(defaultConfig.globalEffectStrength == 0);
        CHECK(defaultConfig.width == 1);
        CHECK(defaultConfig.height == 1);
        CHECK(defaultConfig.revenue == 0);
        CHECK(defaultConfig.buildTime == 0);
        CHECK(defaultConfig.entityType == EntityType::UNKNOWN);
        CHECK(defaultConfig.size == Size::SMALL);
    }

    SUBCASE("Parameterized constructor")
    {
        Cost cost(100, 50, 20, 10);
        EntityConfig customConfig(cost, 5, 3, "H", 10, 5, 2, 4, 4, 2000, 6, EntityType::HOUSE, Size::MEDIUM);

        CHECK(customConfig.cost.moneyCost == 100);
        CHECK(customConfig.cost.woodCost == 50);
        CHECK(customConfig.cost.stoneCost == 20);
        CHECK(customConfig.cost.concreteCost == 10);
        CHECK(customConfig.electricityConsumption == 5);
        CHECK(customConfig.waterConsumption == 3);
        CHECK(customConfig.symbol == "H");
        CHECK(customConfig.effectRadius == 10);
        CHECK(customConfig.localEffectStrength == 5);
        CHECK(customConfig.globalEffectStrength == 2);
        CHECK(customConfig.width == 4);
        CHECK(customConfig.height == 4);
        CHECK(customConfig.revenue == 2000);
        CHECK(customConfig.buildTime == 6);
        CHECK(customConfig.entityType == EntityType::HOUSE);
        CHECK(customConfig.size == Size::MEDIUM);
    }
}
