#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"

TEST_SUITE("PowerPlantLevelTwoUpgrade Tests") {
    // TEST_CASE("PowerPlantLevelTwoUpgrade constructor") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelTwoUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("PowerPlantLevelTwoUpgrade update()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelTwoUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("PowerPlantLevelTwoUpgrade clone()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelTwoUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     PowerPlantLevelTwoUpgrade* cloned = dynamic_cast<PowerPlantLevelTwoUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("PowerPlantLevelTwoUpgrade getOutput()") {
    //     PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    //     PowerPlantLevelTwoUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}