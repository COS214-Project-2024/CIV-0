#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelOneUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"

TEST_SUITE("SewageSystemLevelOneUpgrade Tests") {
    // TEST_CASE("SewageSystemLevelOneUpgrade constructor") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelOneUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("SewageSystemLevelOneUpgrade update()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelOneUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("SewageSystemLevelOneUpgrade clone()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelOneUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     SewageSystemLevelOneUpgrade* cloned = dynamic_cast<SewageSystemLevelOneUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("SewageSystemLevelOneUpgrade getOutput()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelOneUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}