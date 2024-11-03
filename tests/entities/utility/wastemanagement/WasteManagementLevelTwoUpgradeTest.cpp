#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelTwoUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/utility/wastemanagement/WasteManagementLevelThreeUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("WasteManagementLevelTwoUpgrade Tests")
{
    int const UPGRADE = 4;

    TEST_CASE("WasteManagementLevelTwoUpgrade constructor")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WasteManagementLevelTwoUpgrade update()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::MEDIUM);
        WasteManagement basePlant(ec, Size::MEDIUM, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("WasteManagementLevelTwoUpgrade clone()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::LARGE);
        WasteManagement basePlant(ec, Size::LARGE, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        Entity *clonedUpgrade = upgrade.clone();
        WasteManagementLevelTwoUpgrade *cloned = dynamic_cast<WasteManagementLevelTwoUpgrade *>(clonedUpgrade);

        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == basePlant.getOutput() * UPGRADE);
        CHECK(cloned->getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));

        delete clonedUpgrade;
    }

    TEST_CASE("WasteManagementLevelTwoUpgrade getOutput()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == basePlant.getOutput() * UPGRADE);
    }

    TEST_CASE("WasteManagementLevelTwoUpgrade getCost()")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 10, 10);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getCost() == Cost(ec.cost.moneyCost * UPGRADE, ec.cost.woodCost * UPGRADE, ec.cost.stoneCost * UPGRADE, ec.cost.concreteCost * UPGRADE));
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL);
        WasteManagement basePlant(ec, Size::SMALL, 0, 0);
        WasteManagementLevelTwoUpgrade upgrade(&basePlant);
        Entity *upgradedEntity = upgrade.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<WasteManagementLevelThreeUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}
