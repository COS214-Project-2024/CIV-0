#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlantLevelTwoUpgrade Tests")
{
    int const UPGRADE = 4;

    TEST_CASE("PowerPlantLevelTwoUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM);
        PowerPlant basePlant(ec, Size::MEDIUM, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant basePlant(ec, Size::LARGE, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        PowerPlantLevelTwoUpgrade *cloned = dynamic_cast<PowerPlantLevelTwoUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 10, 10);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant basePlant(ec, Size::SMALL, 0, 0);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<PowerPlantLevelThreeUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}