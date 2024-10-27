#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WasteManagement Tests") {
    TEST_CASE("Constructor Test") {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(wasteManagement.getXPosition() == 10);
        CHECK(wasteManagement.getYPosition() == 10);
        CHECK(wasteManagement.getWidth() == 5);
        CHECK(wasteManagement.getHeight() == 5);
        CHECK(wasteManagement.getRevenue() == 0);
        CHECK(wasteManagement.getOutput() == 20);
        CHECK(wasteManagement.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        wasteManagement.setXPosition(10);
        wasteManagement.setYPosition(15);
        CHECK(wasteManagement.getXPosition() == 10);
        CHECK(wasteManagement.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagement copiedWasteManagement(&wasteManagement);
        CHECK(copiedWasteManagement.getXPosition() == wasteManagement.getXPosition());
        CHECK(copiedWasteManagement.getYPosition() == wasteManagement.getYPosition());
        CHECK(copiedWasteManagement.getWidth() == wasteManagement.getWidth());
        CHECK(copiedWasteManagement.getHeight() == wasteManagement.getHeight());
        CHECK(copiedWasteManagement.getRevenue() == wasteManagement.getRevenue());
        CHECK(copiedWasteManagement.getOutput() == wasteManagement.getOutput());
        CHECK(copiedWasteManagement.isBuilt() == wasteManagement.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagement* clonedWasteManagement = static_cast<WasteManagement*>(wasteManagement.clone());
        REQUIRE(clonedWasteManagement != nullptr);
        CHECK(clonedWasteManagement->getXPosition() == wasteManagement.getXPosition());
        CHECK(clonedWasteManagement->getYPosition() == wasteManagement.getYPosition());
        CHECK(clonedWasteManagement->getWidth() == wasteManagement.getWidth());
        CHECK(clonedWasteManagement->getHeight() == wasteManagement.getHeight());
        CHECK(clonedWasteManagement->getRevenue() == wasteManagement.getRevenue());
        CHECK(clonedWasteManagement->getOutput() == wasteManagement.getOutput());
        CHECK(clonedWasteManagement->isBuilt() == wasteManagement.isBuilt());
        delete clonedWasteManagement;
    }

    TEST_CASE("Update Method Test") {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(wasteManagement.isBuilt() == false);

        // This simulates the game looping
        while (!wasteManagement.isBuilt()) {
            wasteManagement.update();
        }

        CHECK(wasteManagement.isBuilt() == true);
    }

    TEST_CASE("Set Output Test") {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        wasteManagement.setOutput(150);
        CHECK(wasteManagement.getOutput() == 150);
    }

    TEST_CASE("Revenue Test") {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(wasteManagement.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test") {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        CHECK(wasteManagement.getWidth() == 5);
        CHECK(wasteManagement.getHeight() == 5);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        WasteManagement baseWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 0, 0);
        
        SUBCASE("WasteManagement within radius") {
            WasteManagement nearbyWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 5, 5);
            CHECK(baseWasteManagement.isWithinEffectRadius(&nearbyWasteManagement) == true);
        }

        SUBCASE("WasteManagement outside radius") {
            WasteManagement farWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 15, 15);
            CHECK(baseWasteManagement.isWithinEffectRadius(&farWasteManagement) == false);
        }

        SUBCASE("WasteManagement exactly on border") {
            WasteManagement borderWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
            CHECK(baseWasteManagement.isWithinEffectRadius(&borderWasteManagement) == false);
        }

        SUBCASE("WasteManagement partially overlaps with radius") {
            WasteManagement partialOverlapWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 9, 9);
            CHECK(baseWasteManagement.isWithinEffectRadius(&partialOverlapWasteManagement) == true);
        }
    }
}
