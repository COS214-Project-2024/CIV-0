#include "doctest.h"
#include "entities/building/amenity/Theater.h"
#include "utils/ConfigManager.h"

TEST_SUITE("Theater Tests")
{
    TEST_CASE("Constructor Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL);
        Theater theater(ec, Size::SMALL, 0, 0);
        CHECK(theater.getXPosition() == 0);
        CHECK(theater.getYPosition() == 0);
        CHECK(theater.getWidth() == ec.width);
        CHECK(theater.getHeight() == ec.height);
        CHECK(theater.getRevenue() == ec.revenue);
        CHECK(theater.isBuilt() == false);
    }

    TEST_CASE("Set Position Test")
    {
        Theater theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::MEDIUM), Size::MEDIUM, 0, 0);
        theater.setXPosition(10);
        theater.setYPosition(15);
        CHECK(theater.getXPosition() == 10);
        CHECK(theater.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test")
    {
        Theater theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 0, 0);
        Theater copiedTheater(&theater);
        CHECK(copiedTheater.getXPosition() == theater.getXPosition());
        CHECK(copiedTheater.getYPosition() == theater.getYPosition());
        CHECK(copiedTheater.getWidth() == theater.getWidth());
        CHECK(copiedTheater.getHeight() == theater.getHeight());
        CHECK(copiedTheater.getRevenue() == theater.getRevenue());
        CHECK(copiedTheater.isBuilt() == theater.isBuilt());
    }

    TEST_CASE("Clone Method Test")
    {
        Theater theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 0, 0);
        Theater *clonedTheater = static_cast<Theater *>(theater.clone());
        REQUIRE(clonedTheater != nullptr);
        CHECK(clonedTheater->getXPosition() == theater.getXPosition());
        CHECK(clonedTheater->getYPosition() == theater.getYPosition());
        CHECK(clonedTheater->getWidth() == theater.getWidth());
        CHECK(clonedTheater->getHeight() == theater.getHeight());
        CHECK(clonedTheater->getRevenue() == theater.getRevenue());
        CHECK(clonedTheater->isBuilt() == theater.isBuilt());
        delete clonedTheater;
    }

    TEST_CASE("Update Method Test")
    {
        Theater theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(theater.isBuilt() == false);

        // This simulates the game looping
        for (int i = 0; i < 3; i++)
        {
            theater.update();
        }

        CHECK(theater.isBuilt() == true);
    }

    TEST_CASE("Revenue Test")
    {
        Theater theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(theater.getRevenue() == 15000);
    }

    TEST_CASE("Dimensions Test")
    {
        Theater theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(theater.getWidth() == 10);
        CHECK(theater.getHeight() == 10);
    }

    TEST_CASE("isWithinEffectRadius Test")
    {
        Theater baseTheater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 0, 0);

        SUBCASE("Theater within radius")
        {
            Theater nearbyTheater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 10, 10);
            CHECK(baseTheater.isWithinEffectRadius(&nearbyTheater) == true);
        }

        SUBCASE("Theater outside radius")
        {
            Theater farTheater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseTheater.isWithinEffectRadius(&farTheater) == false);
        }

        SUBCASE("Theater exactly on border")
        {
            Theater borderTheater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 25, 25);
            CHECK(baseTheater.isWithinEffectRadius(&borderTheater) == true);
        }

        SUBCASE("Theater partially overlaps with radius")
        {
            Theater partialOverlapTheater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::LARGE), Size::LARGE, 24, 24);
            CHECK(baseTheater.isWithinEffectRadius(&partialOverlapTheater) == true);
        }
    }
}
