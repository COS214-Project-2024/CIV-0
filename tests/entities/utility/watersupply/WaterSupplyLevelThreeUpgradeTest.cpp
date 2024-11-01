#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelThreeUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WaterSupplyLevelThreeUpgrade Tests")
{
    int const UPGRADE = 6;

    TEST_CASE("WaterSupplyLevelThreeUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ec, Size::SMALL, 10, 10);
        WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelThreeUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::MEDIUM);
        WaterSupply basePlant(ec, Size::MEDIUM, 10, 10);
        WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelThreeUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE);
        WaterSupply basePlant(ec, Size::LARGE, 10, 10);
        WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        WaterSupplyLevelThreeUpgrade *cloned = dynamic_cast<WaterSupplyLevelThreeUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WaterSupplyLevelThreeUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ec, Size::SMALL, 10, 10);
        WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("WaterSupplyLevelThreeUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ec, Size::SMALL, 10, 10);
        WaterSupplyLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ec, Size::SMALL, 0, 0);
        WaterSupplyLevelThreeUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        CHECK(upgradedEntity == nullptr);
    }
}
