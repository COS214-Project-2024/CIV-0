#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelThreeUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WasteManagementLevelThreeUpgrade Tests")
{
    int const UPGRADE = 6;

    TEST_CASE("WasteManagementLevelThreeUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WasteManagementLevelThreeUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::MEDIUM);
        WasteManagement basePlant(ec, Size::MEDIUM, 10, 10);
        WasteManagementLevelThreeUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WasteManagementLevelThreeUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::LARGE);
        WasteManagement basePlant(ec, Size::LARGE, 10, 10);
        WasteManagementLevelThreeUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        WasteManagementLevelThreeUpgrade *cloned = dynamic_cast<WasteManagementLevelThreeUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WasteManagementLevelThreeUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("WasteManagementLevelThreeUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 0, 0);
        WasteManagementLevelThreeUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        CHECK(upgradedEntity == nullptr);
    }
}
