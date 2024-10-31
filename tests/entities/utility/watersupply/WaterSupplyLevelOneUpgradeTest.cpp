#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelOneUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WaterSupplyLevelOneUpgrade Tests")
{
    int const UPGRADE = 2;

    TEST_CASE("WaterSupplyLevelOneUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelOneUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::MEDIUM);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::MEDIUM), Size::MEDIUM, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelOneUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE), Size::LARGE, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        WaterSupplyLevelOneUpgrade *cloned = dynamic_cast<WaterSupplyLevelOneUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WaterSupplyLevelOneUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("WaterSupplyLevelOneUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 0, 0);
        WaterSupplyLevelOneUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<WaterSupplyLevelTwoUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
