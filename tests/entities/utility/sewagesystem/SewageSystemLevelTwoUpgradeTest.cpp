#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("SewageSystemLevelTwoUpgrade Tests")
{
    int const UPGRADE = 4;

    TEST_CASE("SewageSystemLevelTwoUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM), Size::MEDIUM, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE), Size::LARGE, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        SewageSystemLevelTwoUpgrade *cloned = dynamic_cast<SewageSystemLevelTwoUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 0, 0);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<SewageSystemLevelThreeUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
