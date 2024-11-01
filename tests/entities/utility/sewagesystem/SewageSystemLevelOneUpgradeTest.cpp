#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelOneUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include "utils/ConfigManager.h"
#include <iostream>

TEST_SUITE("SewageSystemLevelOneUpgrade Tests")
{
    int const UPGRADE = 2;

    TEST_CASE("SewageSystemLevelOneUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ec, Size::SMALL, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelOneUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM);
        SewageSystem basePlant(ec, Size::MEDIUM, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelOneUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE);
        SewageSystem basePlant(ec, Size::LARGE, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        SewageSystemLevelOneUpgrade *cloned = dynamic_cast<SewageSystemLevelOneUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("SewageSystemLevelOneUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ec, Size::SMALL, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("SewageSystemLevelOneUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ec, Size::SMALL, 10, 10);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ec, Size::SMALL, 0, 0);
        SewageSystemLevelOneUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<SewageSystemLevelTwoUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
