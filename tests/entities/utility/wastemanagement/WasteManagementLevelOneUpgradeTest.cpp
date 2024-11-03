#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelOneUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WasteManagementLevelOneUpgrade Tests")
{
    int const UPGRADE = 2;

    TEST_CASE("WasteManagementLevelOneUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WasteManagementLevelOneUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::MEDIUM);
        WasteManagement basePlant(ec, Size::MEDIUM, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WasteManagementLevelOneUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::LARGE);
        WasteManagement basePlant(ec, Size::LARGE, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        WasteManagementLevelOneUpgrade *cloned = dynamic_cast<WasteManagementLevelOneUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WasteManagementLevelOneUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("WasteManagementLevelOneUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 0, 0);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<WasteManagementLevelTwoUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
