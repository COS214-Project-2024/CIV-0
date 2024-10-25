#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WaterSupplyLevelTwoUpgrade Tests") {
    TEST_CASE("WaterSupplyLevelTwoUpgrade constructor") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 4);
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade update()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::MEDIUM), Size::MEDIUM, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * 4);
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade clone()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE), Size::LARGE, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        WaterSupplyLevelTwoUpgrade* cloned = dynamic_cast<WaterSupplyLevelTwoUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * 4);

        delete clonedUpgrade;
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade getOutput()") {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 4);
    }
}