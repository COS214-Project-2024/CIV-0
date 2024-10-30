#include "doctest.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/utility/watersupply/WaterSupplyLevelOneUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WaterSupply Tests") {
    TEST_CASE("Constructor Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(waterSupply.getXPosition() == 10);
        CHECK(waterSupply.getYPosition() == 10);
        CHECK(waterSupply.getWidth() == 6);
        CHECK(waterSupply.getHeight() == 6);
        CHECK(waterSupply.getRevenue() == 0);
        CHECK(waterSupply.getOutput() == 20);
        CHECK(waterSupply.getCost() == Cost(1500, 700, 300, 200));
        CHECK(waterSupply.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        waterSupply.setXPosition(10);
        waterSupply.setYPosition(15);
        CHECK(waterSupply.getXPosition() == 10);
        CHECK(waterSupply.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupply copiedWaterSupply(&waterSupply);
        CHECK(copiedWaterSupply.getXPosition() == waterSupply.getXPosition());
        CHECK(copiedWaterSupply.getYPosition() == waterSupply.getYPosition());
        CHECK(copiedWaterSupply.getWidth() == waterSupply.getWidth());
        CHECK(copiedWaterSupply.getHeight() == waterSupply.getHeight());
        CHECK(copiedWaterSupply.getRevenue() == waterSupply.getRevenue());
        CHECK(copiedWaterSupply.getOutput() == waterSupply.getOutput());
        CHECK(copiedWaterSupply.getCost() == waterSupply.getCost());
        CHECK(copiedWaterSupply.isBuilt() == waterSupply.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupply* clonedWaterSupply = static_cast<WaterSupply*>(waterSupply.clone());
        REQUIRE(clonedWaterSupply != nullptr);
        CHECK(clonedWaterSupply->getXPosition() == waterSupply.getXPosition());
        CHECK(clonedWaterSupply->getYPosition() == waterSupply.getYPosition());
        CHECK(clonedWaterSupply->getWidth() == waterSupply.getWidth());
        CHECK(clonedWaterSupply->getHeight() == waterSupply.getHeight());
        CHECK(clonedWaterSupply->getRevenue() == waterSupply.getRevenue());
        CHECK(clonedWaterSupply->getOutput() == waterSupply.getOutput());
        CHECK(clonedWaterSupply->getCost() == waterSupply.getCost());
        CHECK(clonedWaterSupply->isBuilt() == waterSupply.isBuilt());
        delete clonedWaterSupply;
    }

    TEST_CASE("Update Method Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(waterSupply.isBuilt() == false);
        
        // This simulates the game looping
        for(int i = 0; i < 3; i++) {
            waterSupply.update();
        }

        CHECK(waterSupply.isBuilt() == true);
    }

    TEST_CASE("Set Output Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        waterSupply.setOutput(150);
        CHECK(waterSupply.getOutput() == 150);
    }

    TEST_CASE("Cost Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(waterSupply.getCost() == Cost(4000, 1200, 600, 400));
    }

    TEST_CASE("Revenue Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(waterSupply.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(waterSupply.getWidth() == 6);
        CHECK(waterSupply.getHeight() == 6);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        WaterSupply baseWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 0, 0);
        
        SUBCASE("WaterSupply within radius") {
            WaterSupply nearbyWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
            CHECK(baseWaterSupply.isWithinEffectRadius(&nearbyWaterSupply) == true);
        }

        SUBCASE("WaterSupply outside radius") {
            WaterSupply farWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 20, 20);
            CHECK(baseWaterSupply.isWithinEffectRadius(&farWaterSupply) == false);
        }

        SUBCASE("WaterSupply exactly on border") {
            WaterSupply borderWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 14, 14);
            CHECK(baseWaterSupply.isWithinEffectRadius(&borderWaterSupply) == false);
        }

        SUBCASE("WaterSupply partially overlaps with radius") {
            WaterSupply partialOverlapWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 13, 13);
            CHECK(baseWaterSupply.isWithinEffectRadius(&partialOverlapWaterSupply) == true);
        }
    }

    TEST_CASE("Upgrade test") {
        WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 0, 0);
        Entity* upgradedEntity = waterSupply.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<WaterSupplyLevelOneUpgrade*>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
