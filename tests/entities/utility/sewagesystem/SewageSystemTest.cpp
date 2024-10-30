#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "utils/ConfigManager.h"

TEST_SUITE("SewageSystem Tests") {
    TEST_CASE("Constructor Test") {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(sewageSystem.getXPosition() == 10);
        CHECK(sewageSystem.getYPosition() == 10);
        CHECK(sewageSystem.getWidth() == 5);
        CHECK(sewageSystem.getHeight() == 5);
        CHECK(sewageSystem.getRevenue() == 0);
        CHECK(sewageSystem.getOutput() == 20);
        CHECK(sewageSystem.getCost() == Cost(1000, 500, 200, 150));
        CHECK(sewageSystem.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM), Size::MEDIUM, 10, 10);
        sewageSystem.setXPosition(10);
        sewageSystem.setYPosition(15);
        CHECK(sewageSystem.getXPosition() == 10);
        CHECK(sewageSystem.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
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

    TEST_CASE("Clone Method Test") {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystem* clonedSewageSystem = static_cast<SewageSystem*>(sewageSystem.clone());
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

    TEST_CASE("Update Method Test") {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(sewageSystem.isBuilt() == false);
        
        // This simulates the game looping
        for(int i = 0; i < 3; i++) {
            sewageSystem.update();
        }

        CHECK(sewageSystem.isBuilt() == true);
    }

    TEST_CASE("Output Test") {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        sewageSystem.setOutput(150);
        CHECK(sewageSystem.getOutput() == 150);
    }

    TEST_CASE("Cost Test") {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(sewageSystem.getCost() == Cost(2500, 1000, 400, 300));
    }

    TEST_CASE("Revenue Test") {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(sewageSystem.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test") {
        SewageSystem sewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(sewageSystem.getWidth() == 5);
        CHECK(sewageSystem.getHeight() == 5);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        SewageSystem baseSewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 0, 0);
        
        SUBCASE("SewageSystem within radius") {
            SewageSystem nearbySewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 5, 5);
            CHECK(baseSewageSystem.isWithinEffectRadius(&nearbySewageSystem) == true);
        }

        SUBCASE("SewageSystem outside radius") {
            SewageSystem farSewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 15, 15);
            CHECK(baseSewageSystem.isWithinEffectRadius(&farSewageSystem) == false);
        }

        SUBCASE("SewageSystem exactly on border") {
            SewageSystem borderSewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
            CHECK(baseSewageSystem.isWithinEffectRadius(&borderSewageSystem) == false);
        }

        SUBCASE("SewageSystem partially overlaps with radius") {
            SewageSystem partialOverlapSewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 9, 9);
            CHECK(baseSewageSystem.isWithinEffectRadius(&partialOverlapSewageSystem) == true);
        }
    }
}
