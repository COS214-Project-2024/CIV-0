#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelOneUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"

TEST_SUITE("WaterSupplyLevelOneUpgrade Tests") {
    // TEST_CASE("WaterSupplyLevelOneUpgrade constructor") {
    //     WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupplyLevelOneUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("WaterSupplyLevelOneUpgrade update()") {
    //     WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupplyLevelOneUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("WaterSupplyLevelOneUpgrade clone()") {
    //     WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupplyLevelOneUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     WaterSupplyLevelOneUpgrade* cloned = dynamic_cast<WaterSupplyLevelOneUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("WaterSupplyLevelOneUpgrade getOutput()") {
    //     WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupplyLevelOneUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}