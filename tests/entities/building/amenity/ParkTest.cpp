#include "doctest.h"
#include "entities/building/amenity/Park.h"
#include "utils/ConfigManager.h"

TEST_SUITE("Park Tests")
{
    TEST_CASE("Constructor Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::PARK, Size::SMALL);
        Park park(ec, Size::SMALL, 0, 0);
        CHECK(park.getXPosition() == 0);
        CHECK(park.getYPosition() == 0);
        CHECK(park.getWidth() == ec.width);
        CHECK(park.getHeight() == ec.height);
        CHECK(park.getRevenue() == ec.revenue);
        CHECK(park.isBuilt() == false);
    }

    TEST_CASE("Set Position Test")
    {
        Park park(ConfigManager::getEntityConfig(EntityType::PARK, Size::MEDIUM), Size::MEDIUM, 0, 0);
        park.setXPosition(10);
        park.setYPosition(15);
        CHECK(park.getXPosition() == 10);
        CHECK(park.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test")
    {
        Park park(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 0, 0);
        Park copiedPark(&park);
        CHECK(copiedPark.getXPosition() == park.getXPosition());
        CHECK(copiedPark.getYPosition() == park.getYPosition());
        CHECK(copiedPark.getWidth() == park.getWidth());
        CHECK(copiedPark.getHeight() == park.getHeight());
        CHECK(copiedPark.getRevenue() == park.getRevenue());
        CHECK(copiedPark.isBuilt() == park.isBuilt());
    }

    TEST_CASE("Clone Method Test")
    {
        Park park(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 0, 0);
        Park *clonedPark = static_cast<Park *>(park.clone());
        REQUIRE(clonedPark != nullptr);
        CHECK(clonedPark->getXPosition() == park.getXPosition());
        CHECK(clonedPark->getYPosition() == park.getYPosition());
        CHECK(clonedPark->getWidth() == park.getWidth());
        CHECK(clonedPark->getHeight() == park.getHeight());
        CHECK(clonedPark->getRevenue() == park.getRevenue());
        CHECK(clonedPark->isBuilt() == park.isBuilt());
        delete clonedPark;
    }

    TEST_CASE("Update Method Test")
    {
        Park park(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(park.isBuilt() == false);

        // This simulates the game looping
        for (int i = 0; i < 3; i++)
        {
            park.update();
        }

        CHECK(park.isBuilt() == true);
    }

    TEST_CASE("Revenue Test")
    {
        Park park(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(park.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE);
        Park park(ec, Size::LARGE, 0, 0);
        CHECK(park.getWidth() == ec.width);
        CHECK(park.getHeight() == ec.height);
    }

    TEST_CASE("isWithinEffectRadius Test")
    {
        Park basePark(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 0, 0);

        SUBCASE("Park within radius")
        {
            Park nearbyPark(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 10, 10);
            CHECK(basePark.isWithinEffectRadius(&nearbyPark) == true);
        }

        SUBCASE("Park outside radius")
        {
            Park farPark(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(basePark.isWithinEffectRadius(&farPark) == false);
        }

        SUBCASE("Park exactly on border")
        {
            Park borderPark(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 19, 19);
            CHECK(basePark.isWithinEffectRadius(&borderPark) == false);
        }

        SUBCASE("Park partially overlaps with radius")
        {
            Park partialOverlapPark(ConfigManager::getEntityConfig(EntityType::PARK, Size::LARGE), Size::LARGE, 18, 18);
            CHECK(basePark.isWithinEffectRadius(&partialOverlapPark) == false);
        }
    }
}
