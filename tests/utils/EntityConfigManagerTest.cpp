#include "doctest.h"
#include "utils/EntityConfigManager.h"
#include <stdexcept>

TEST_CASE("EntityConfigManagerTest test")
{
    SUBCASE("Get Config for existing entity and size")
    {
        EntityConfig houseSmall = EntityConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL);
        CHECK(houseSmall.cost.moneyCost == 100);
        CHECK(houseSmall.symbol == "H");

        EntityConfig factoryLarge = EntityConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE);
        CHECK(factoryLarge.cost.moneyCost == 1000);
        CHECK(factoryLarge.electricityConsumption == 50.0f);
        CHECK(factoryLarge.symbol == "F");
    }

    SUBCASE("Invalid config throws exception")
    {
        CHECK_THROWS_AS(EntityConfigManager::getEntityConfig(static_cast<EntityType>(100), Size::SMALL), std::out_of_range);
    }
}
