#include "doctest.h"
#include "entities/building/service/PoliceStation.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PoliceStation Tests") {
    TEST_CASE("Constructor Test") {
        PoliceStation police(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(police.getXPosition() == 0);
        CHECK(police.getYPosition() == 0);
        CHECK(police.getWidth() == 4);
        CHECK(police.getHeight() == 4);
        CHECK(police.getRevenue() == 4000);
        CHECK(police.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        PoliceStation police(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::MEDIUM), Size::MEDIUM, 0, 0);
        police.setXPosition(10);
        police.setYPosition(15);
        CHECK(police.getXPosition() == 10);
        CHECK(police.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        PoliceStation police(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 0, 0);
        PoliceStation copiedPoliceStation(&police);
        CHECK(copiedPoliceStation.getXPosition() == police.getXPosition());
        CHECK(copiedPoliceStation.getYPosition() == police.getYPosition());
        CHECK(copiedPoliceStation.getWidth() == police.getWidth());
        CHECK(copiedPoliceStation.getHeight() == police.getHeight());
        CHECK(copiedPoliceStation.getRevenue() == police.getRevenue());
        CHECK(copiedPoliceStation.isBuilt() == police.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        PoliceStation police(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 0, 0);
        PoliceStation* clonedPoliceStation = static_cast<PoliceStation*>(police.clone());
        REQUIRE(clonedPoliceStation != nullptr);
        CHECK(clonedPoliceStation->getXPosition() == police.getXPosition());
        CHECK(clonedPoliceStation->getYPosition() == police.getYPosition());
        CHECK(clonedPoliceStation->getWidth() == police.getWidth());
        CHECK(clonedPoliceStation->getHeight() == police.getHeight());
        CHECK(clonedPoliceStation->getRevenue() == police.getRevenue());
        CHECK(clonedPoliceStation->isBuilt() == police.isBuilt());
        delete clonedPoliceStation;
    }

    TEST_CASE("Update Method Test") {
        PoliceStation police(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(police.isBuilt() == false);

        // This simulates the game looping
        while (!police.isBuilt()) {
            police.update();
        }
        
        CHECK(police.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        PoliceStation police(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(police.getRevenue() == 10000);
    }

    TEST_CASE("Dimensions Test") {
        PoliceStation police(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(police.getWidth() == 8);
        CHECK(police.getHeight() == 8);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        PoliceStation basePoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("PoliceStation within radius") {
            PoliceStation nearbyPoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 15, 15);
            CHECK(basePoliceStation.isWithinEffectRadius(&nearbyPoliceStation) == true);
        }

        SUBCASE("PoliceStation outside radius") {
            PoliceStation farPoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(basePoliceStation.isWithinEffectRadius(&farPoliceStation) == false);
        }

        SUBCASE("PoliceStation exactly on border") {
            PoliceStation borderPoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 23, 23);
            CHECK(basePoliceStation.isWithinEffectRadius(&borderPoliceStation) == false);
        }

        SUBCASE("PoliceStation partially overlaps with radius") {
            PoliceStation partialOverlapPoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::LARGE), Size::LARGE, 22, 22);
            CHECK(basePoliceStation.isWithinEffectRadius(&partialOverlapPoliceStation) == true);
        }
    }
}