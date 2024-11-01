#include "doctest.h"
#include "utils/ConfigManager.h"
#include <stdexcept>

TEST_CASE("ConfigManagerTest test")
{
    SUBCASE("Get Config for existing entity and size")
    {
        EntityConfig houseSmall = ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL);
        CHECK(houseSmall.cost.moneyCost == 100);

        EntityConfig factoryLarge = ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE);
        CHECK(factoryLarge.cost.moneyCost == 1000);
        CHECK(factoryLarge.electricityConsumption == 50.0f);
    }

    SUBCASE("Invalid config throws exception")
    {
        CHECK_THROWS_AS(ConfigManager::getEntityConfig(static_cast<EntityType>(100), Size::SMALL), std::out_of_range);
    }
}
