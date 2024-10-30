#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "utils/ConfigManager.h"

TEST_SUITE("SewageSystemLevelThreeUpgrade Tests") {
    int const UPGRADE = 6;

    TEST_CASE("SewageSystemLevelThreeUpgrade constructor") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(1000 * UPGRADE, 500 * UPGRADE, 200 * UPGRADE, 150 * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade update()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM), Size::MEDIUM, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(1500 * UPGRADE, 800 * UPGRADE, 300 * UPGRADE, 200 * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade clone()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE), Size::LARGE, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        SewageSystemLevelThreeUpgrade* cloned = dynamic_cast<SewageSystemLevelThreeUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * UPGRADE);
        CHECK(cloned->getCost() == Cost(2500 * UPGRADE, 1000 * UPGRADE, 400 * UPGRADE, 300 * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade getOutput()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade getCost()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(1000 * UPGRADE, 500 * UPGRADE, 200 * UPGRADE, 150 * UPGRADE));
    }

    TEST_CASE("Upgrade test") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 0, 0);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);
        Entity* upgradedEntity = upgrade.upgrade();
        CHECK(upgradedEntity == nullptr);
    }
}
