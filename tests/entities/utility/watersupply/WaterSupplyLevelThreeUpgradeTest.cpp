#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelThreeUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"

TEST_SUITE("WaterSupplyLevelThreeUpgrade Tests") {
    // TEST_CASE("WaterSupplyLevelThreeUpgrade constructor") {
    //     WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("WaterSupplyLevelThreeUpgrade update()") {
    //     WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("WaterSupplyLevelThreeUpgrade clone()") {
    //     WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     WaterSupplyLevelThreeUpgrade* cloned = dynamic_cast<WaterSupplyLevelThreeUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("WaterSupplyLevelThreeUpgrade getOutput()") {
    //     WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    //     WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}