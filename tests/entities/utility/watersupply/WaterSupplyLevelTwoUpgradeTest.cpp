#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/utility/watersupply/WaterSupplyLevelThreeUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WaterSupplyLevelTwoUpgrade Tests") {
    int const UPGRADE = 4;

    TEST_CASE("WaterSupplyLevelTwoUpgrade constructor") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(1500 * UPGRADE, 700 * UPGRADE, 300 * UPGRADE, 200 * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade update()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::MEDIUM), Size::MEDIUM, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(2500 * UPGRADE, 900 * UPGRADE, 400 * UPGRADE, 300 * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade clone()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE), Size::LARGE, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        WaterSupplyLevelTwoUpgrade* cloned = dynamic_cast<WaterSupplyLevelTwoUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * UPGRADE);
        CHECK(cloned->getCost() == Cost(4000 * UPGRADE, 1200 * UPGRADE, 600 * UPGRADE, 400 * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade getOutput()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade getCost()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(1500 * UPGRADE, 700 * UPGRADE, 300 * UPGRADE, 200 * UPGRADE));
    }

    TEST_CASE("Upgrade test") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 0, 0);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);
        Entity* upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<WaterSupplyLevelThreeUpgrade*>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
