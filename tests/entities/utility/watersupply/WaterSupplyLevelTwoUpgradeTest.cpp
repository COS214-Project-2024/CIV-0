#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/utility/watersupply/WaterSupplyLevelThreeUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WaterSupplyLevelTwoUpgrade Tests")
{
    int const UPGRADE = 4;

    TEST_CASE("WaterSupplyLevelTwoUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::MEDIUM);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::MEDIUM), Size::MEDIUM, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::LARGE), Size::LARGE, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        WaterSupplyLevelTwoUpgrade *cloned = dynamic_cast<WaterSupplyLevelTwoUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL);
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        WaterSupply basePlant(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 0, 0);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<WaterSupplyLevelThreeUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
