#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelOneUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"

TEST_SUITE("PowerPlantLevelOneUpgrade Tests") {
    // TEST_CASE("PowerPlantLevelOneUpgrade constructor") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM), Size::SMALL, 10, 10);
    //     PowerPlantLevelOneUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("PowerPlantLevelOneUpgrade update()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::SMALL, 10, 10);
    //     PowerPlantLevelOneUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("PowerPlantLevelOneUpgrade clone()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelOneUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     PowerPlantLevelOneUpgrade* cloned = dynamic_cast<PowerPlantLevelOneUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("PowerPlantLevelOneUpgrade getOutput()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::SMALL, 10, 10);
    //     PowerPlantLevelOneUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}