#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlantLevelTwoUpgrade Tests") {
    int const UPGRADE = 4;

    TEST_CASE("PowerPlantLevelTwoUpgrade constructor") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(2000 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE, 300 * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade update()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM), Size::MEDIUM, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(4000 * UPGRADE, 1200 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade clone()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        PowerPlantLevelTwoUpgrade* cloned = dynamic_cast<PowerPlantLevelTwoUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * UPGRADE);
        CHECK(cloned->getCost() == Cost(6000 * UPGRADE, 1600 * UPGRADE, 1000 * UPGRADE, 700 * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade getOutput()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade getCost()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(2000 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE, 300 * UPGRADE));
    }
}
