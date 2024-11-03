#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/utility/wastemanagement/WasteManagementLevelOneUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WasteManagement Tests")
{

    TEST_CASE("Set Position Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement wasteManagement(ec, Size::SMALL, 10, 10);
        wasteManagement.setXPosition(10);
        wasteManagement.setYPosition(15);
        CHECK(wasteManagement.getXPosition() == 10);
        CHECK(wasteManagement.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement wasteManagement(ec, Size::SMALL, 10, 10);
        WasteManagement copiedWasteManagement(&wasteManagement);
        CHECK(copiedWasteManagement.getXPosition() == wasteManagement.getXPosition());
        CHECK(copiedWasteManagement.getYPosition() == wasteManagement.getYPosition());
        CHECK(copiedWasteManagement.getWidth() == wasteManagement.getWidth());
        CHECK(copiedWasteManagement.getHeight() == wasteManagement.getHeight());
        CHECK(copiedWasteManagement.getRevenue() == wasteManagement.getRevenue());
        CHECK(copiedWasteManagement.getOutput() == wasteManagement.getOutput());
        CHECK(copiedWasteManagement.getCost() == wasteManagement.getCost());
        CHECK(copiedWasteManagement.isBuilt() == wasteManagement.isBuilt());
    }

    TEST_CASE("Clone Method Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement wasteManagement(ec, Size::SMALL, 10, 10);
        WasteManagement *clonedWasteManagement = static_cast<WasteManagement *>(wasteManagement.clone());
        REQUIRE(clonedWasteManagement != nullptr);
        CHECK(clonedWasteManagement->getXPosition() == wasteManagement.getXPosition());
        CHECK(clonedWasteManagement->getYPosition() == wasteManagement.getYPosition());
        CHECK(clonedWasteManagement->getWidth() == wasteManagement.getWidth());
        CHECK(clonedWasteManagement->getHeight() == wasteManagement.getHeight());
        CHECK(clonedWasteManagement->getRevenue() == wasteManagement.getRevenue());
        CHECK(clonedWasteManagement->getOutput() == wasteManagement.getOutput());
        CHECK(clonedWasteManagement->getCost() == wasteManagement.getCost());
        CHECK(clonedWasteManagement->isBuilt() == wasteManagement.isBuilt());
        delete clonedWasteManagement;
    }

    TEST_CASE("Update Method Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement wasteManagement(ec, Size::SMALL, 10, 10);
        CHECK(wasteManagement.isBuilt() == false);

        // This simulates the game looping
        for (int i = 0; i < ec.buildTime; i++)
        {
            wasteManagement.update();
        }

        CHECK(wasteManagement.isBuilt() == true);
    }

    TEST_CASE("isWithinEffectRadius Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement baseWasteManagement(ec, Size::SMALL, 0, 0);

        SUBCASE("WasteManagement within radius")
        {
            WasteManagement nearbyWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL), Size::SMALL, 5, 5);
            CHECK(baseWasteManagement.isWithinEffectRadius(&nearbyWasteManagement) == true);
        }

        SUBCASE("WasteManagement outside radius")
        {
            WasteManagement farWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL), Size::SMALL, 15, 15);
            CHECK(baseWasteManagement.isWithinEffectRadius(&farWasteManagement) == false);
        }

        SUBCASE("WasteManagement exactly on border")
        {
            WasteManagement borderWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL), Size::SMALL, 10, 10);
            CHECK(baseWasteManagement.isWithinEffectRadius(&borderWasteManagement) == false);
        }

        SUBCASE("WasteManagement partially overlaps with radius")
        {
            WasteManagement partialOverlapWasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL), Size::SMALL, 9, 9);
            CHECK(baseWasteManagement.isWithinEffectRadius(&partialOverlapWasteManagement) == true);
        }
    }

    TEST_CASE("Upgrade test")
    {
        WasteManagement wasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL), Size::SMALL, 0, 0);
        Entity *upgradedEntity = wasteManagement.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<WasteManagementLevelOneUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
