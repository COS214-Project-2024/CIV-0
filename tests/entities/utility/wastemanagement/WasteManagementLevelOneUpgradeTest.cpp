#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelOneUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WasteManagementLevelOneUpgrade Tests") {
    TEST_CASE("WasteManagementLevelOneUpgrade constructor") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 2);
    }

    TEST_CASE("WasteManagementLevelOneUpgrade update()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::MEDIUM), Size::MEDIUM, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * 2);
    }

    TEST_CASE("WasteManagementLevelOneUpgrade clone()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::LARGE), Size::LARGE, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        WasteManagementLevelOneUpgrade* cloned = dynamic_cast<WasteManagementLevelOneUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * 2);

        delete clonedUpgrade;
    }

    TEST_CASE("WasteManagementLevelOneUpgrade getOutput()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 2);
    }
}