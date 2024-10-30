#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelOneUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlantLevelOneUpgrade Tests") {
    int const UPGRADE = 2;

    TEST_CASE("PowerPlantLevelOneUpgrade constructor") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(2000 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE, 300 * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelOneUpgrade update()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM), Size::MEDIUM, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(4000 * UPGRADE, 1200 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelOneUpgrade clone()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        PowerPlantLevelOneUpgrade* cloned = dynamic_cast<PowerPlantLevelOneUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * UPGRADE);
        CHECK(cloned->getCost() == Cost(6000 * UPGRADE, 1600 * UPGRADE, 1000 * UPGRADE, 700 * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("PowerPlantLevelOneUpgrade getOutput()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
    }

    TEST_CASE("PowerPlantLevelOneUpgrade getCost()") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(2000 * UPGRADE, 800 * UPGRADE, 500 * UPGRADE, 300 * UPGRADE));
    }

    TEST_CASE("Upgrade test") {
        PowerPlant basePlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 0, 0);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);
        Entity* upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<PowerPlantLevelTwoUpgrade*>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}