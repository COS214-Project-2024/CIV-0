#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelOneUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlantLevelOneUpgrade Tests")
{
    int const UPGRADE = 2;

    TEST_CASE("PowerPlantLevelOneUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelOneUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM);
        PowerPlant basePlant(ec, Size::MEDIUM, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelOneUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant basePlant(ec, Size::LARGE, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        PowerPlantLevelOneUpgrade *cloned = dynamic_cast<PowerPlantLevelOneUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("PowerPlantLevelOneUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("PowerPlantLevelOneUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 0, 0);
        PowerPlantLevelOneUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<PowerPlantLevelTwoUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}