#include "doctest.h"
#include "entities/utility/watersupply/WaterSupply.h"

TEST_SUITE("WaterSupply Tests") {
    // TEST_CASE("Constructor Test") {
    //     WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     CHECK(waterSupply.getXPosition() == 0);
    //     CHECK(waterSupply.getYPosition() == 0);
    //     CHECK(waterSupply.getWidth() == 5);
    //     CHECK(waterSupply.getHeight() == 5);
    //     CHECK(waterSupply.getRevenue() == 1000);
    //     CHECK(waterSupply.getOutput() == 20);
    //     CHECK(waterSupply.isBuilt() == false);
    // }

    // TEST_CASE("Set Position Test") {
    //     WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     waterSupply.setXPosition(10);
    //     waterSupply.setYPosition(15);
    //     CHECK(waterSupply.getXPosition() == 10);
    //     CHECK(waterSupply.getYPosition() == 15);
    // }

    // TEST_CASE("Copy Constructor Test") {
    //     WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupply copiedWaterSupply(&waterSupply);
    //     CHECK(copiedWaterSupply.getXPosition() == waterSupply.getXPosition());
    //     CHECK(copiedWaterSupply.getYPosition() == waterSupply.getYPosition());
    //     CHECK(copiedWaterSupply.getWidth() == waterSupply.getWidth());
    //     CHECK(copiedWaterSupply.getHeight() == waterSupply.getHeight());
    //     CHECK(copiedWaterSupply.getRevenue() == waterSupply.getRevenue());
    //     CHECK(copiedWaterSupply.getOutput() == waterSupply.getOutput());
    //     CHECK(copiedWaterSupply.isBuilt() == waterSupply.isBuilt());
    // }

    // TEST_CASE("Clone Method Test") {
    //     WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupply* clonedWaterSupply = static_cast<WaterSupply*>(waterSupply.clone());
    //     REQUIRE(clonedWaterSupply != nullptr);
    //     CHECK(clonedWaterSupply->getXPosition() == waterSupply.getXPosition());
    //     CHECK(clonedWaterSupply->getYPosition() == waterSupply.getYPosition());
    //     CHECK(clonedWaterSupply->getWidth() == waterSupply.getWidth());
    //     CHECK(clonedWaterSupply->getHeight() == waterSupply.getHeight());
    //     CHECK(clonedWaterSupply->getRevenue() == waterSupply.getRevenue());
    //     CHECK(clonedWaterSupply->getOutput() == waterSupply.getOutput());
    //     CHECK(clonedWaterSupply->isBuilt() == waterSupply.isBuilt());
    //     delete clonedWaterSupply;
    // }

    // TEST_CASE("Update Method Test") {
    //     WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     CHECK(waterSupply.isBuilt() == false);
    //     waterSupply.update();
    //     CHECK(waterSupply.isBuilt() == true);
    // }

    // TEST_CASE("Set Output Test") {
    //     WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     waterSupply.setOutput(150);
    //     CHECK(waterSupply.getOutput() == 150);
    // }

    // TEST_CASE("Capacity Test") {
    //     WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     CHECK(waterSupply.getRevenue() == 1000);
    // }

    // TEST_CASE("Dimensions Test") {
    //     WaterSupply waterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     CHECK(waterSupply.getWidth() == 5);
    //     CHECK(waterSupply.getHeight() == 5);
    // }

    // TEST_CASE("isWithinEffectRadius Test") {
    //     WaterSupply baseWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        
    //     SUBCASE("WaterSupply within radius") {
    //         WaterSupply nearbyWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //         CHECK(baseWaterSupply.isWithinEffectRadius(&nearbyWaterSupply) == true);
    //     }

    //     SUBCASE("WaterSupply outside radius") {
    //         WaterSupply farWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //         CHECK(baseWaterSupply.isWithinEffectRadius(&farWaterSupply) == false);
    //     }

    //     SUBCASE("WaterSupply exactly on border") {
    //         WaterSupply borderWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //         CHECK(baseWaterSupply.isWithinEffectRadius(&borderWaterSupply) == false);
    //     }

    //     SUBCASE("WaterSupply partially overlaps with radius") {
    //         WaterSupply partialOverlapWaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //         CHECK(baseWaterSupply.isWithinEffectRadius(&partialOverlapWaterSupply) == true);
    //     }
    // }
}