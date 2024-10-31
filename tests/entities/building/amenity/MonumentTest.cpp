#include "doctest.h"
#include "entities/building/amenity/Monument.h"
#include "utils/ConfigManager.h"

TEST_SUITE("Monument Tests")
{
    TEST_CASE("Constructor Test")
    {
        Monument monument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(monument.getXPosition() == 0);
        CHECK(monument.getYPosition() == 0);
        CHECK(monument.getWidth() == 5);
        CHECK(monument.getHeight() == 5);
        CHECK(monument.getRevenue() == 0);
        CHECK(monument.isBuilt() == false);
    }

    TEST_CASE("Set Position Test")
    {
        Monument monument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::MEDIUM), Size::MEDIUM, 0, 0);
        monument.setXPosition(10);
        monument.setYPosition(15);
        CHECK(monument.getXPosition() == 10);
        CHECK(monument.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test")
    {
        Monument monument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 0, 0);
        Monument copiedMonument(&monument);
        CHECK(copiedMonument.getXPosition() == monument.getXPosition());
        CHECK(copiedMonument.getYPosition() == monument.getYPosition());
        CHECK(copiedMonument.getWidth() == monument.getWidth());
        CHECK(copiedMonument.getHeight() == monument.getHeight());
        CHECK(copiedMonument.getRevenue() == monument.getRevenue());
        CHECK(copiedMonument.isBuilt() == monument.isBuilt());
    }

    TEST_CASE("Clone Method Test")
    {
        Monument monument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 0, 0);
        Monument *clonedMonument = static_cast<Monument *>(monument.clone());
        REQUIRE(clonedMonument != nullptr);
        CHECK(clonedMonument->getXPosition() == monument.getXPosition());
        CHECK(clonedMonument->getYPosition() == monument.getYPosition());
        CHECK(clonedMonument->getWidth() == monument.getWidth());
        CHECK(clonedMonument->getHeight() == monument.getHeight());
        CHECK(clonedMonument->getRevenue() == monument.getRevenue());
        CHECK(clonedMonument->isBuilt() == monument.isBuilt());
        delete clonedMonument;
    }

    TEST_CASE("Update Method Test")
    {
        Monument monument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(monument.isBuilt() == false);

        // This simulates the game looping
        for (int i = 0; i < 3; i++)
        {
            monument.update();
        }

        CHECK(monument.isBuilt() == true);
    }

    TEST_CASE("Revenue Test")
    {
        Monument monument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(monument.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test")
    {
        Monument monument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(monument.getWidth() == 10);
        CHECK(monument.getHeight() == 10);
    }

    TEST_CASE("isWithinEffectRadius Test")
    {
        Monument baseMonument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 0, 0);

        SUBCASE("Monument within radius")
        {
            Monument nearbyMonument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 15, 15);
            CHECK(baseMonument.isWithinEffectRadius(&nearbyMonument) == true);
        }

        SUBCASE("Monument outside radius")
        {
            Monument farMonument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseMonument.isWithinEffectRadius(&farMonument) == false);
        }

        SUBCASE("Monument exactly on border")
        {
            Monument borderMonument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 30, 30);
            CHECK(baseMonument.isWithinEffectRadius(&borderMonument) == false);
        }

        SUBCASE("Monument partially overlaps with radius")
        {
            Monument partialOverlapMonument(ConfigManager::getEntityConfig(EntityType::MONUMENT, Size::LARGE), Size::LARGE, 29, 29);
            CHECK(baseMonument.isWithinEffectRadius(&partialOverlapMonument) == true);
        }
    }
}
