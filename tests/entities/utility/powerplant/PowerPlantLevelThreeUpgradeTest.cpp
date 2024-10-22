#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"

TEST_SUITE("PowerPlantLevelThreeUpgrade Tests") {
    // TEST_CASE("PowerPlantLevelThreeUpgrade constructor") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelThreeUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("PowerPlantLevelThreeUpgrade update()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelThreeUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("PowerPlantLevelThreeUpgrade clone()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelThreeUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     PowerPlantLevelThreeUpgrade* cloned = dynamic_cast<PowerPlantLevelThreeUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("PowerPlantLevelThreeUpgrade getOutput()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelThreeUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}