#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelThreeUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"

TEST_SUITE("WasteManagementLevelThreeUpgrade Tests") {
    // TEST_CASE("WasteManagementLevelThreeUpgrade constructor") {
    //     WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
    //     WasteManagementLevelThreeUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("WasteManagementLevelThreeUpgrade update()") {
    //     WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
    //     WasteManagementLevelThreeUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("WasteManagementLevelThreeUpgrade clone()") {
    //     WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
    //     WasteManagementLevelThreeUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     WasteManagementLevelThreeUpgrade* cloned = dynamic_cast<WasteManagementLevelThreeUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("WasteManagementLevelThreeUpgrade getOutput()") {
    //     WasteManagement basePlant(ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL), Size::SMALL, 10, 10);
    //     WasteManagementLevelThreeUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}