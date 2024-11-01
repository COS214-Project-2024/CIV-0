#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlantLevelThreeUpgrade Tests")
{
    int const UPGRADE = 6;

    TEST_CASE("PowerPlantLevelThreeUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM);
        PowerPlant basePlant(ec, Size::MEDIUM, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant basePlant(ec, Size::LARGE, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        PowerPlantLevelThreeUpgrade *cloned = dynamic_cast<PowerPlantLevelThreeUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("PowerPlantLevelThreeUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 0, 0);
        PowerPlantLevelThreeUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        CHECK(upgradedEntity == nullptr);
    }
}