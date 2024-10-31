#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "utils/ConfigManager.h"

TEST_SUITE("SewageSystemLevelThreeUpgrade Tests")
{
    int const UPGRADE = 6;

    TEST_CASE("SewageSystemLevelThreeUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM), Size::MEDIUM, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE), Size::LARGE, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        SewageSystemLevelThreeUpgrade *cloned = dynamic_cast<SewageSystemLevelThreeUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL);
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 0, 0);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        CHECK(upgradedEntity == nullptr);
    }
}
