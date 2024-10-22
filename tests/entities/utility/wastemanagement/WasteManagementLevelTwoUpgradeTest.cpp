#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"

TEST_SUITE("WasteManagementLevelTwoUpgrade Tests") {
    // TEST_CASE("WasteManagementLevelTwoUpgrade constructor") {
    //     WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
    //     WasteManagementLevelTwoUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("WasteManagementLevelTwoUpgrade update()") {
    //     WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
    //     WasteManagementLevelTwoUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("WasteManagementLevelTwoUpgrade clone()") {
    //     WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
    //     WasteManagementLevelTwoUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     WasteManagementLevelTwoUpgrade* cloned = dynamic_cast<WasteManagementLevelTwoUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("WasteManagementLevelTwoUpgrade getOutput()") {
    //     WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
    //     WasteManagementLevelTwoUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}