#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/utility/sewagesystem/SewageSystemLevelOneUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("SewageSystem Tests")
{

    TEST_CASE("Set Position Test")
    {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM), Size::MEDIUM, 10, 10);
        sewageSystem.setXPosition(10);
        sewageSystem.setYPosition(15);
        CHECK(sewageSystem.getXPosition() == 10);
        CHECK(sewageSystem.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test")
    {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE), Size::LARGE, 10, 10);
        SewageSystem copiedSewageSystem(&sewageSystem);
        CHECK(copiedSewageSystem.getXPosition() == sewageSystem.getXPosition());
        CHECK(copiedSewageSystem.getYPosition() == sewageSystem.getYPosition());
        CHECK(copiedSewageSystem.getWidth() == sewageSystem.getWidth());
        CHECK(copiedSewageSystem.getHeight() == sewageSystem.getHeight());
        CHECK(copiedSewageSystem.getRevenue() == sewageSystem.getRevenue());
        CHECK(copiedSewageSystem.getOutput() == sewageSystem.getOutput());
        CHECK(copiedSewageSystem.getCost() == sewageSystem.getCost());
        CHECK(copiedSewageSystem.isBuilt() == sewageSystem.isBuilt());
    }

    TEST_CASE("Clone Method Test")
    {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystem *clonedSewageSystem = static_cast<SewageSystem *>(sewageSystem.clone());
        REQUIRE(clonedSewageSystem != nullptr);
        CHECK(clonedSewageSystem->getXPosition() == sewageSystem.getXPosition());
        CHECK(clonedSewageSystem->getYPosition() == sewageSystem.getYPosition());
        CHECK(clonedSewageSystem->getWidth() == sewageSystem.getWidth());
        CHECK(clonedSewageSystem->getHeight() == sewageSystem.getHeight());
        CHECK(clonedSewageSystem->getRevenue() == sewageSystem.getRevenue());
        CHECK(clonedSewageSystem->getOutput() == sewageSystem.getOutput());
        CHECK(clonedSewageSystem->getCost() == sewageSystem.getCost());
        CHECK(clonedSewageSystem->isBuilt() == sewageSystem.isBuilt());
        delete clonedSewageSystem;
    }

    TEST_CASE("Update Method Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(sewageSystem.isBuilt() == false);

        // This simulates the game looping
        for (int i = 0; i < ec.buildTime; i++)
        {
            sewageSystem.update();
        }

        CHECK(sewageSystem.isBuilt() == true);
    }

    TEST_CASE("isWithinEffectRadius Test")
    {
        SewageSystem baseSewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 0, 0);

        SUBCASE("SewageSystem within radius")
        {
            SewageSystem nearbySewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 5, 5);
            CHECK(baseSewageSystem.isWithinEffectRadius(&nearbySewageSystem) == true);
        }

        SUBCASE("SewageSystem outside radius")
        {
            SewageSystem farSewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 15, 15);
            CHECK(baseSewageSystem.isWithinEffectRadius(&farSewageSystem) == false);
        }

        SUBCASE("SewageSystem exactly on border")
        {
            SewageSystem borderSewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
            CHECK(baseSewageSystem.isWithinEffectRadius(&borderSewageSystem) == true);
        }

        SUBCASE("SewageSystem partially overlaps with radius")
        {
            SewageSystem partialOverlapSewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 9, 9);
            CHECK(baseSewageSystem.isWithinEffectRadius(&partialOverlapSewageSystem) == true);
        }
    }

    TEST_CASE("Upgrade test")
    {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 0, 0);
        Entity *upgradedEntity = sewageSystem.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<SewageSystemLevelOneUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}