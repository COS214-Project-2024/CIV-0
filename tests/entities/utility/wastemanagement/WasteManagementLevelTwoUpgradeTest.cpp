#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WasteManagementLevelTwoUpgrade Tests") {
    TEST_CASE("WasteManagementLevelTwoUpgrade constructor") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 4);
    }

    TEST_CASE("WasteManagementLevelTwoUpgrade update()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::MEDIUM), Size::MEDIUM, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * 4);
    }

    TEST_CASE("WasteManagementLevelTwoUpgrade clone()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::LARGE), Size::LARGE, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        WasteManagementLevelTwoUpgrade* cloned = dynamic_cast<WasteManagementLevelTwoUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * 4);

        delete clonedUpgrade;
    }

    TEST_CASE("WasteManagementLevelTwoUpgrade getOutput()") {
        WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 4);
    }
}
