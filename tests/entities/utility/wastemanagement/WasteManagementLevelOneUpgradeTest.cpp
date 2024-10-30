#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelOneUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WasteManagementLevelOneUpgrade Tests") {
    int const UPGRADE = 2;

    TEST_CASE("WasteManagementLevelOneUpgrade constructor") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(800 * UPGRADE, 400 * UPGRADE, 200 * UPGRADE, 100 * UPGRADE));
    }

    TEST_CASE("WasteManagementLevelOneUpgrade update()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::MEDIUM), Size::MEDIUM, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(1200 * UPGRADE, 600 * UPGRADE, 300 * UPGRADE, 200 * UPGRADE));
    }

    TEST_CASE("WasteManagementLevelOneUpgrade clone()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::LARGE), Size::LARGE, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        WasteManagementLevelOneUpgrade* cloned = dynamic_cast<WasteManagementLevelOneUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * UPGRADE);
        CHECK(cloned->getCost() == Cost(1800 * UPGRADE, 800 * UPGRADE, 400 * UPGRADE, 300 * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WasteManagementLevelOneUpgrade getOutput()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
    }

    TEST_CASE("WasteManagementLevelOneUpgrade getCost()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(800 * UPGRADE, 400 * UPGRADE, 200 * UPGRADE, 100 * UPGRADE));
    }

    TEST_CASE("Upgrade test") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 0, 0);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);
        Entity* upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<WasteManagementLevelTwoUpgrade*>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
