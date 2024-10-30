#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelOneUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WaterSupplyLevelOneUpgrade Tests") {
    int const UPGRADE = 2;

    TEST_CASE("WaterSupplyLevelOneUpgrade constructor") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(1500 * UPGRADE, 700 * UPGRADE, 300 * UPGRADE, 200 * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelOneUpgrade update()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::MEDIUM), Size::MEDIUM, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(2500 * UPGRADE, 900 * UPGRADE, 400 * UPGRADE, 300 * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelOneUpgrade clone()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE), Size::LARGE, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        WaterSupplyLevelOneUpgrade* cloned = dynamic_cast<WaterSupplyLevelOneUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * UPGRADE);
        CHECK(cloned->getCost() == Cost(4000 * UPGRADE, 1200 * UPGRADE, 600 * UPGRADE, 400 * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WaterSupplyLevelOneUpgrade getOutput()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
    }

    TEST_CASE("WaterSupplyLevelOneUpgrade getCost()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(1500 * UPGRADE, 700 * UPGRADE, 300 * UPGRADE, 200 * UPGRADE));
    }
}
