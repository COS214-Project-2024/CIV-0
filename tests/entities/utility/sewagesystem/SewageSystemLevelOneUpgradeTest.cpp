#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelOneUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include "utils/ConfigManager.h"
#include <iostream>

TEST_SUITE("SewageSystemLevelOneUpgrade Tests") {
    int const UPGRADE = 2;

    TEST_CASE("SewageSystemLevelOneUpgrade constructor") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(1000 * UPGRADE, 500 * UPGRADE, 200 * UPGRADE, 150 * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelOneUpgrade update()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM), Size::MEDIUM, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * UPGRADE);
        CHECK(upgrade.getCost() == Cost(1500 * UPGRADE, 800 * UPGRADE, 300 * UPGRADE, 200 * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelOneUpgrade clone()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE), Size::LARGE, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        SewageSystemLevelOneUpgrade* cloned = dynamic_cast<SewageSystemLevelOneUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * UPGRADE);
        CHECK(cloned->getCost() == Cost(2500 * UPGRADE, 1000 * UPGRADE, 400 * UPGRADE, 300 * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("SewageSystemLevelOneUpgrade getOutput()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * UPGRADE);
    }

    TEST_CASE("SewageSystemLevelOneUpgrade getCost()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(1000 * UPGRADE, 500 * UPGRADE, 200 * UPGRADE, 150 * UPGRADE));
    }

    TEST_CASE("Upgrade test") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 0, 0);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);
        Entity* upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<SewageSystemLevelTwoUpgrade*>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
