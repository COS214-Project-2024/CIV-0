#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlantLevelThreeUpgrade Tests") {
    TEST_CASE("PowerPlantLevelThreeUpgrade constructor") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 6);
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade update()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM), Size::MEDIUM, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * 6);
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade clone()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        PowerPlantLevelThreeUpgrade* cloned = dynamic_cast<PowerPlantLevelThreeUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * 6);

        delete clonedUpgrade;
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade getOutput()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 6);
    }
}