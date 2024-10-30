#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlantLevelThreeUpgrade Tests") {
    int const UPGRADE = 6;

    TEST_CASE("PowerPlantLevelThreeUpgrade constructor") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(2000 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE, 300 * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade update()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM), Size::MEDIUM, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(4000 * UPGRADE, 1200 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade clone()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        PowerPlantLevelThreeUpgrade* cloned = dynamic_cast<PowerPlantLevelThreeUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * UPGRADE);
        CHECK(cloned->getCost() == Cost(6000 * UPGRADE, 1600 * UPGRADE, 1000 * UPGRADE, 700 * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade getOutput()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade getCost()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(2000 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE, 300 * UPGRADE));
    }

    TEST_CASE("Upgrade test") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 0, 0);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);
        Entity* upgradedEntity = upgrade.upgrade();
        CHECK(upgradedEntity == nullptr);
    }
}